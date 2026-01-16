#include <iostream>
#include "Fixed.hpp"

/*
** Print the current raw fixed-point value of an instance.
** Used to observe state changes during tests.
*/
static void	print_state(const char *name, const Fixed &f)
{
	int	value;

	value = f.getRawBits();
	std::cout << name << " raw bits = " << value << std::endl;
}

/*
** Verify that self-assignment does not alter the object's state.
** Ensures operator= correctly handles a = a.
*/
static void	self_assignment(Fixed &a)
{
	std::cout << "\n=== Self-assignment ===" << std::endl;
	a.setRawBits(42);
	print_state("a (before)", a);
	Fixed	&alias = a;
	a = alias;
	print_state("a (after)", a); 
}

/*
** Verify chained assignment behavior.
** Confirms operator= returns a reference and assignments propagate correctly.
*/
static void	chained_assignment(Fixed &a)
{
	std::cout << "\n=== Chained assignment ===" << std::endl;
	Fixed d;
	Fixed e;

	d.setRawBits(7);
	e.setRawBits(21);
	a = d = e;
	print_state("a", a);
	print_state("d", d);
	print_state("e", e);
}

/*
** Verify that the copy constructor creates an independent copy.
** Modifying the copy must not affect the original object.
*/
static void	independence_after_copy(const Fixed &src)
{
	std::cout << "\n=== Independence after copy ===" << std::endl;
	Fixed copy(src);

	print_state("src (before)", src);
	print_state("copy (before)", copy);
	copy.setRawBits(100);
	print_state("src (after copy modified)", src);
	print_state("copy (after)", copy);
}

/*
** Verify that the assignment operator creates an independent object.
** Modifying the assigned instance must not affect the source.
*/
static void	independence_after_assignment(const Fixed &src)
{
	std::cout << "\n=== Independence after assignment ===" << std::endl;
	Fixed assigned;

	assigned = src;
	print_state("src (before)", src);
	print_state("assigned (before)", assigned);
	assigned.setRawBits(200);
	print_state("src (after assigned modified)", src);
	print_state("assigned (after)", assigned);
	std::cout << std::endl;
}

int main(void)
{
	std::cout << "=== Default construction ===" << std::endl;
	Fixed a;
	print_state("a", a);

	std::cout << "\n=== Copy constructor ===" << std::endl;
	Fixed b(a);
	print_state("a", a);
	print_state("b", b);

	std::cout << "\n=== Copy assignment ===" << std::endl;
	Fixed c;
	c = b;
	print_state("b", b);
	print_state("c", c);

	self_assignment(a);
	chained_assignment(a);
	independence_after_copy(a);
	independence_after_assignment(a);

	return 0;
}
