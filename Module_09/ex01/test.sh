#!/bin/bash

run() {
  echo
  echo "============================================================"
  echo "$1"
  echo "Command: $2"
  echo "Expected: $3"
  echo "------------------------------------------------------------"
  eval "$2"
}

echo "### RPN test suite ###"
echo "Binary: ./RPN"
echo

# --- Happy path (subject examples) ---
run "Test 1 (subject example)" \
'./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"' \
"42"

run "Test 2 (subject example)" \
'./RPN "7 7 * 7 -"' \
"42"

run "Test 3 (subject example)" \
'./RPN "1 2 * 2 / 2 * 2 4 - +"' \
"0"

# --- Basic operations ---
run "Add"  './RPN "3 4 +"' "7"
run "Sub"  './RPN "9 3 -"' "6"
run "Mul"  './RPN "6 7 *"' "42"
run "Div"  './RPN "8 2 /"' "4"

# --- Negative results (allowed) ---
run "Negative result" './RPN "1 9 -"' "-8"

# --- Whitespace robustness ---
run "Extra spaces" './RPN "   8   9   *   "' "72"
run "Tabs/newlines via $'' quoting" $'./RPN "8\t9\t*"' "72"

# --- Error cases: invalid tokens / forbidden syntax ---
run "Parentheses forbidden" './RPN "(1 + 1)"' "Error"
run "Letter token" './RPN "1 a +"' "Error"
run "Decimal forbidden" './RPN "1 2.5 +"' "Error"
run "Multi-digit forbidden (<10 rule)" './RPN "10 2 +"' "Error"
run "Operator glued to number token" './RPN "8 9*"' "Error"

# --- Error cases: stack underflow / malformed expression ---
run "Too few operands" './RPN "1 +"' "Error"
run "Operator first" './RPN "+ 1 2"' "Error"
run "Only operator" './RPN "*"' "Error"
run "Trailing operands (leftover stack)" './RPN "1 2 3 +"' "Error"
run "Empty string" './RPN ""' "Error"

# --- Error cases: division by zero ---
run "Division by zero" './RPN "1 0 /"' "Error"

# --- Argument errors (main should print Error) ---
run "No argument" './RPN' "Error"
run "Too many arguments" './RPN "1 2 +" "extra"' "Error"

echo
echo "### End of test suite ###"

# Manual tests
# ./RPN "(1 + 1)" 1>out.txt 2>err.txt	# Test to where "Error" is printed
# ./RPN "1+1" | echo $?			# Test error code 1 when "Error"
