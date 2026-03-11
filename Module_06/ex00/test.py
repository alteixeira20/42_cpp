#!/usr/bin/env python3
import os
import re
import subprocess
from dataclasses import dataclass
from typing import Callable, List, Tuple, Optional

BIN = "./converter"

# ---------- minimal colors ----------
NO_COLOR = os.environ.get("NO_COLOR", "0") == "1"
def _c(code: str) -> str:
    return "" if NO_COLOR else f"\033[{code}m"

RESET = _c("0")
BOLD  = _c("1")
DIM   = _c("2")
RED   = _c("31")
GREEN = _c("32")
BLUE  = _c("34")
GRAY  = _c("90")

def ok(s: str) -> str:   return f"{GREEN}{s}{RESET}"
def bad(s: str) -> str:  return f"{RED}{s}{RESET}"
def head(s: str) -> str: return f"{BOLD}{BLUE}{s}{RESET}"
def info(s: str) -> str: return f"{DIM}{GRAY}{s}{RESET}"

# ---------- run / normalize ----------
def run_prog(args: List[str]) -> Tuple[int, str, str]:
    p = subprocess.run(args, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
    return p.returncode, p.stdout, p.stderr

def normalize(out: str) -> List[str]:
    lines: List[str] = []
    for ln in out.splitlines():
        ln = ln.strip("\n")
        if not ln.strip():
            continue
        if ln.lstrip().startswith("[DEBUG]"):
            continue
        lines.append(ln.strip())
    return lines

def cmd_show(args: List[str]) -> str:
    def show(a: str) -> str:
        if a == "" or any(ch.isspace() for ch in a):
            return repr(a)
        return a
    return " ".join(show(a) for a in args)

# ---------- strict line validators ----------
CHAR_RE = re.compile(r"^char:\s*(impossible|Non displayable|'(.)')$")
INT_RE  = re.compile(r"^int:\s*(impossible|[-+]?\d+)$")

# Accept:
#   - impossible
#   - nanf
#   - +inff / -inff
#   - numeric float with exactly ONE trailing 'f'
#     supports:
#       12.3f, 12.0f, 0.42f, .42f (if you ever output that), 2.14748e+09f
# Rejects:
#   - 42.001ff  (two trailing f's)
#   - 42.001.0f (two dots)
FLOAT_RE = re.compile(
    r"^float:\s*("
    r"impossible|nanf|[+-]inff|"
    r"[+-]?(?:\d+(?:\.\d*)?|\.\d+)(?:[eE][+-]?\d+)?f"
    r")$"
)

DOUBLE_RE = re.compile(
    r"^double:\s*("
    r"impossible|nan|[+-]inf|"
    r"[+-]?(?:\d+(?:\.\d*)?|\.\d+)(?:[eE][+-]?\d+)?"
    r")$"
)

def must_have_4(lines: List[str]) -> Tuple[bool, str]:
    if len(lines) != 4:
        return False, f"Expected 4 output lines, got {len(lines)}"
    return True, "ok"

def must_match_line(lines: List[str], idx: int, rx: re.Pattern, label: str) -> Tuple[bool, str]:
    if idx >= len(lines):
        return False, f"Missing {label} line"
    if not rx.fullmatch(lines[idx]):
        return False, f"{label} format invalid: {lines[idx]}"
    return True, "ok"

def check_invalid(lines: List[str]) -> Tuple[bool, str]:
    exp = [
        "char: impossible",
        "int: impossible",
        "float: impossible",
        "double: impossible",
    ]
    if lines != exp:
        return False, "INVALID must be exactly 4 lines of 'impossible'"
    return True, "ok"

def check_usage(lines: List[str]) -> Tuple[bool, str]:
    if any("Usage:" in ln for ln in lines):
        return True, "ok"
    return False, "Expected Usage line"

def check_pseudo(lines: List[str], kind: str) -> Tuple[bool, str]:
    if kind == "nan":
        exp = ["char: impossible", "int: impossible", "float: nanf", "double: nan"]
    elif kind == "+inf":
        exp = ["char: impossible", "int: impossible", "float: +inff", "double: +inf"]
    elif kind == "-inf":
        exp = ["char: impossible", "int: impossible", "float: -inff", "double: -inf"]
    else:
        return False, "Unknown pseudo kind"

    if lines != exp:
        return False, f"Pseudo output mismatch (expected {exp})"
    return True, "ok"

def is_scientific(text: str) -> bool:
    return "e" in text or "E" in text

def has_integer_suffix(text: str, suffix: str) -> bool:
    if not text.endswith(suffix):
        return False
    body = text[:-len(suffix)] if suffix else text
    if is_scientific(body):
        return True
    return body.endswith(".0")

def check_general(lines: List[str], integer_like: bool) -> Tuple[bool, str]:
    ok4, reason = must_have_4(lines)
    if not ok4:
        return ok4, reason

    okc, reason = must_match_line(lines, 0, CHAR_RE, "char")
    if not okc:
        return okc, reason
    oki, reason = must_match_line(lines, 1, INT_RE, "int")
    if not oki:
        return oki, reason
    okf, reason = must_match_line(lines, 2, FLOAT_RE, "float")
    if not okf:
        return okf, reason
    okd, reason = must_match_line(lines, 3, DOUBLE_RE, "double")
    if not okd:
        return okd, reason

    # Extra strong guard: catches '42.001.0f' style even if regex changes
    fl = lines[2].split(":", 1)[1].strip()
    if fl not in ("impossible", "nanf", "+inff", "-inff") and fl.count(".") > 1:
        return False, "Float has more than one '.' (malformed)"
    if fl.endswith("ff"):
        return False, "Float ends with 'ff' (must be exactly one trailing 'f')"

    # Enforce subject-style .0f / .0 for integer-like test inputs
    # while still accepting scientific notation for large values.
    if integer_like:
        fl_text = lines[2].split(":", 1)[1].strip()
        dl_text = lines[3].split(":", 1)[1].strip()
        if fl_text != "impossible" and not has_integer_suffix(fl_text, "f"):
            return False, "Integer-like: float must end with '.0f' unless scientific notation is used"
        if dl_text != "impossible" and not has_integer_suffix(dl_text, ""):
            return False, "Integer-like: double must end with '.0' unless scientific notation is used"

    return True, "ok"

# ---------- tests ----------
@dataclass
class TestCase:
    group: str
    name: str
    args: List[str]
    check: Callable[[List[str]], Tuple[bool, str]]

def main() -> int:
    if not (os.path.exists(BIN) and os.access(BIN, os.X_OK)):
        print(bad(f"[ERROR] {BIN} not found or not executable. Build first (make)."))
        return 1

    tests: List[TestCase] = []

    # USAGE
    tests.append(TestCase("USAGE", "no args", [BIN], check_usage))
    tests.append(TestCase("USAGE", "too many args", [BIN, "1", "2"], check_usage))

    # INVALID (strict)
    invalids = [
        ("empty string", ""),
        ("alphabetic", "abc"),
        ("mixed alpha+digits", "abc123"),
        ("multiple signs", "++++42"),
        ("double dot", "1..0"),
        ("double f suffix", "1.0ff"),
        ("trailing junk", "42abc"),
        ("dot + f", ".f"),
        ("fake pseudo", "+infff"),
        ("hex-like", "0x2A"),
        ("comma decimal", "3,14"),
        ("leading/trailing spaces", " 42 "),
        ("internal space", "4 2"),
    ]
    for name, s in invalids:
        tests.append(TestCase("INVALID", name, [BIN, s], check_invalid))

    # PSEUDO (strict normalized)
    for s in ["nan", "nanf"]:
        tests.append(TestCase("PSEUDO", s, [BIN, s], lambda L: check_pseudo(L, "nan")))
    for s in ["+inf", "+inff"]:
        tests.append(TestCase("PSEUDO", s, [BIN, s], lambda L: check_pseudo(L, "+inf")))
    for s in ["-inf", "-inff"]:
        tests.append(TestCase("PSEUDO", s, [BIN, s], lambda L: check_pseudo(L, "-inf")))

    # CHAR literals: structural only (no integer-like strictness)
    for s in ["a", "*", " ", "\t", "+", "-", "."]:
        tests.append(TestCase("CHAR", repr(s), [BIN, s], lambda L: check_general(L, integer_like=False)))

    # VALID integer-like cases: strict .0f/.0 style
    integer_like_inputs = [
        "0", "1", "-1", "+42", "42",
        "42.0", "42.", "0.0f", "1.0f", "-1.0f", "42.0f",
        "42.99999", "42.999987",
        "2147483647", "-2147483648",
    ]
    for s in integer_like_inputs:
        tests.append(TestCase("VALID", s, [BIN, s], lambda L: check_general(L, integer_like=True)))

    # VALID non-integer: still strict float grammar (catches 42.001ff / 42.001.0f)
    non_integer_inputs = [
        "3.14", "-3.14", "42.011", ".42", "3.14f", "42.001f", "42.001",
    ]
    for s in non_integer_inputs:
        tests.append(TestCase("VALID", s, [BIN, s], lambda L: check_general(L, integer_like=False)))

    passed = 0
    failed = 0
    current: Optional[str] = None

    for tc in tests:
        if tc.group != current:
            print()
            print(head(f"== {tc.group} =="))
            current = tc.group

        rc, out, err = run_prog(tc.args)
        lines = normalize(out)

        ok_flag, reason = tc.check(lines)
        if ok_flag:
            passed += 1
            print(f"{ok('PASS'):>6} {tc.name:<24} {info(cmd_show(tc.args))}")
        else:
            failed += 1
            print(f"{bad('FAIL'):>6} {tc.name:<24} {info(cmd_show(tc.args))}")
            print(info(f"      reason: {reason}"))
            print(info("      output:"))
            for ln in lines:
                print(info(f"        {ln}"))

    total = passed + failed
    print()
    print(f"{BOLD}{GREEN if failed == 0 else RED}Summary:{RESET} {passed}/{total} passed, {failed} failed")
    if failed != 0:
        print(info("Tip: NO_COLOR=1 disables colors."))
        return 2
    return 0

if __name__ == "__main__":
    raise SystemExit(main())
