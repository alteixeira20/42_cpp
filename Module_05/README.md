<p align="center">
  <img src="https://img.shields.io/badge/C%2B%2B98-004482?style=for-the-badge&logo=cplusplus&logoColor=white" alt="C++98 badge">
  <img src="https://img.shields.io/badge/Exceptions-0A5F38?style=for-the-badge&logoColor=white" alt="Exceptions badge">
  <img src="https://img.shields.io/badge/Canonical%20Form-7C3AED?style=for-the-badge&logoColor=white" alt="Canonical form badge">
  <img src="https://img.shields.io/badge/Abstract%20Forms-1D3557?style=for-the-badge&logoColor=white" alt="Abstract forms badge">
  <img src="https://img.shields.io/badge/Factory%20Pattern-B23A48?style=for-the-badge&logoColor=white" alt="Factory badge">
</p>

<h1 align="center">Module 05 — Repetition & Exceptions</h1>
<p align="center">Grades, signatures, executable forms, and an intern that manufactures paperwork on demand.</p>

## Table of Contents
1. [At a Glance](#at-a-glance)
2. [Learning Objectives](#learning-objectives)
3. [Key Concepts to Review](#key-concepts-to-review)
4. [Exercises Overview](#exercises-overview)
5. [Implementation Notes per Exercise](#implementation-notes-per-exercise)
6. [Rules & Constraints](#rules--constraints)
7. [Approach & Tips](#approach--tips)
8. [What to Deliver](#what-to-deliver)
9. [Looking Ahead](#looking-ahead)

## At a Glance
> **Highlights:** turn Module 04 polymorphism into controlled, exception-driven workflows.
- `Bureaucrat` enforces the grade range `1..150` and throws on invalid construction or promotion/demotion.
- `Form` in `ex01` introduces sign requirements and explicit error reporting through `signForm()`.
- `AForm` in `ex02` centralizes execution checks, while derived forms implement only their concrete action.
- `Intern` in `ex03` acts as a small factory that maps form names to heap-allocated concrete instances.

## Learning Objectives
> **Goal:** design class hierarchies that fail safely and communicate clearly.
- Use custom exceptions derived from `std::exception`.
- Enforce invariants at construction time and on every state transition.
- Separate common validation logic from specialized behavior with an abstract base class.
- Practice exception-aware collaboration between classes (`Bureaucrat`, `Form`, `AForm`, `Intern`).
- Keep ownership explicit when a factory returns dynamically allocated objects.

## Key Concepts to Review
> **Refresh before coding.**
- Why grade `1` is higher than grade `150`, and how that flips intuition in comparisons.
- Exception propagation with `try` / `catch`, plus `what()` overrides.
- Orthodox Canonical Form in small class hierarchies.
- Abstract base classes and pure virtual functions.
- Factory-style dispatch without a long `if/else if/else` chain.
- File output with `std::ofstream` for side-effect-driven forms like shrubbery creation.

## Exercises Overview
> **What this module builds in this repo.**

| Exercise | Purpose | Focus |
| :------: | ------- | ----- |
| `ex00` Bureaucrat | Introduce bounded grades and exceptions. | Invariants, custom exceptions, canonical form. |
| `ex01` Form | Add signable paperwork controlled by bureaucrat grade. | Collaboration between classes, explicit failure messages. |
| `ex02` AForm + concrete forms | Execute real actions through an abstract base. | Template-method style design, runtime behavior, side effects. |
| `ex03` Intern | Create forms from names at runtime. | Factory mapping, heap ownership, cleaner dispatch. |

## Implementation Notes per Exercise
- **ex00:** `Bureaucrat` stores a `const` name and mutable grade, rejects invalid grades in the constructor, and throws `GradeTooHighException` / `GradeTooLowException` when crossing limits. The test driver covers normal promotion/demotion, constructor failures, limit failures, and copy/assignment.  
  Run: `make -C ex00 && ./ex00/Bureaucrat`

- **ex01:** `Form` adds immutable signing and execution thresholds plus mutable `_isSigned`. `Bureaucrat::signForm()` wraps `Form::beSigned()` and prints either the success line or the failure reason exactly through exception handling. Your `main.cpp` tests invalid form grades and both successful and failed signing scenarios.  
  Run: `make -C ex01 && ./ex01/Form`

- **ex02:** `Form` becomes abstract as `AForm`, and execution checks now live in `AForm::execute()`: first signed-state validation, then executor-grade validation, then delegation to `executeAction()`.  
  The three concrete forms are implemented exactly as the subject requests:
  - `ShrubberyCreationForm`: writes a tree to `<target>_shrubbery`.
  - `RobotomyRequestForm`: prints drilling noises and succeeds about 50% of the time.
  - `PresidentialPardonForm`: prints the Zaphod Beeblebrox pardon message.  
  Your test driver also covers executing unsigned forms and execution with grades that are too low.  
  Run: `make -C ex02 && ./ex02/Forms`

- **ex03:** `Intern::makeForm()` uses a compact name-to-constructor mapping with three creator functions instead of a long condition chain, which matches the subject’s intent. It returns heap-allocated `AForm*`, prints `Intern creates <form>` on success, and throws `FormNotFoundException` on unknown names after printing an explicit error. `main.cpp` validates all three known forms, unknown names, execution without signing, and low-grade failures.  
  Run: `make -C ex03 && ./ex03/Intern`

## Rules & Constraints
> **Non-negotiables from the subject.**
- Compile with `c++ -Wall -Wextra -Werror`, still compatible with `-std=c++98`.
- Forbidden: `printf`, `malloc`, `free`, external libraries, `using namespace`, `friend`.
- STL containers and algorithms remain off-limits until Modules 08 and 09.
- Class files and names must match the subject exactly.
- From Module 02 onward, classes are expected to follow Orthodox Canonical Form unless the exercise says otherwise.

## Approach & Tips
> **What matters during implementation.**
- Validate grades immediately in constructors so invalid objects never exist.
- Keep the exception type aligned with the violated rule: high for `< 1`, low for `> 150`.
- Put shared execution checks in `AForm::execute()` and keep concrete forms focused on their side effect.
- When a factory returns `AForm*`, make ownership obvious in `main` and always `delete` what was created.
- Test both the happy path and the failure path for every form; Module 05 is mostly about controlled failure.

## What to Deliver
> **Turn-in checklist per exercise.**
- `ex00`: `Makefile`, `main.cpp`, `Bureaucrat.{hpp,cpp}`
- `ex01`: previous files + `Form.{hpp,cpp}`
- `ex02`: `Makefile`, `main.cpp`, `Bureaucrat.*`, `AForm.*`, `ShrubberyCreationForm.*`, `RobotomyRequestForm.*`, `PresidentialPardonForm.*`
- `ex03`: previous files + `Intern.{hpp,cpp}`

## Looking Ahead
> **How this connects to later modules.**
- Module 06 builds on this exception and polymorphism discipline with casts, serialization, and RTTI.
- The command-style form hierarchy here is a clean precursor to factory and dispatch patterns used later.
- The habit of centralizing validation before action remains critical once templates and containers enter the cursus.

## Snippets from This Repo
- Grade protection in `Bureaucrat`:
```cpp
void	Bureaucrat::incrementGrade()
{
	if (this->_grade <= GRADE_HIGHEST)
		throw GradeTooHighException();
	this->_grade--;
}
```

- Centralized execution guard in `AForm`:
```cpp
void	AForm::execute(const Bureaucrat &executor) const
{
	if (this->_isSigned == false)
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > this->_gradeToExecute)
		throw AForm::GradeTooLowException();
	this->executeAction();
}
```

- Intern factory mapping in `ex03`:
```cpp
const std::string	names[3] = {
	"shrubbery creation",
	"robotomy request",
	"presidential pardon"
};

AForm*	(*creators[3])(const std::string &) = {
	&createShrubbery,
	&createRobotomy,
	&createPresidential
};
```
