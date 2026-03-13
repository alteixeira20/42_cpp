#include <iostream>
#include <string>
#include "Array.hpp"

static void	printTitle(const std::string &title)
{
	std::cout << "=== " << title << " ===" << std::endl;
}

static void	testDefaultConstructor()
{
	Array<int>	a;

	printTitle("Default constructor (empty array)");

	std::cout << "size = " << a.size() << std::endl;
	try
	{
		std::cout << a[0] << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Access a[0] throws: " << e.what() << std::endl;
	}
}

static void	testConstructorWithSize()
{
	size_t	i;
	Array<int>	a(5);

	printTitle("Custom constructor");

	
	std::cout << "size = " << a.size() << std::endl;
	i = 0;
	while (i < a.size())
	{
		std::cout << "a[" << i << "] = " << a[i] << std::endl;
		i++;
	}

	i = 0;
	while (i < a.size())
	{
		a[i] = (int)(i * 10);
		i++;
	}
	std::cout << "After write:" << std::endl;

	i = 0;
	while (i < a.size())
	{
		std::cout << "a[" << i << "] = " << a[i] << std::endl;
		i++;
	}
}

static void	testConstOperator()
{
	Array<int>		tmp(3);

	printTitle("Const operator[]");
	
	tmp[0] = 42;
	tmp[1] = 41;
	tmp[2] = 40;

	const Array<int>	a(tmp);
	std::cout << "a[0] = " << a[0] << std::endl;
	std::cout << "a[1] = " << a[1] << std::endl;
	std::cout << "a[2] = " << a[2] << std::endl;

	// a[0] = 42; // Should not compile (const operator[])
}

static void	testCopyConstructor()
{
	Array<int>	orig(3);

	printTitle("Copy constructor");

	orig[0] = 4;
	orig[1] = 2;
	orig[2] = 42;
	
	Array<int>	copy(orig);
	copy[1] = 999;

	std::cout << "orig[1] = " << orig[1] << " (should be 2)" << std::endl;
	std::cout << "copy[1] = " << copy[1] << " (should be 999)" << std::endl;
}

static void	testAssignmentDeepCopy()
{
	Array<int>	orig(3);

	printTitle("Assignment deep copy");

	orig[0] = 1;
	orig[1] = 2;
	orig[2] = 3;

	Array<int> assign(3);
	assign = orig;
	assign[0] = 42;
	
	std::cout << "orig[0] = " << orig[0] << " (should be 1)" << std::endl;
	std::cout << "assign[0] = " << assign[0] << " (should be 42)" << std::endl;

	orig = orig;
	std::cout << "self-assign: orig[2] = " << orig[2] << " (should be 3)" << std::endl;
}

static void	testOutOfBounds()
{
	Array<int>	a(3);
	printTitle("Out of bounds exceptions");

	try
	{
		a[-1] = 0;
	}
	catch (const std::exception &e)
	{
		std::cout << "a[-1] throws: " << e.what() << std::endl;
	}
	try
	{
		a[a.size()] = 0;
	}
	catch (const std::exception &e)
	{
		std::cout << "a[" << a.size() << "] throws: " << e.what() << std::endl;
	}
}

static void	testTypeDouble()
{
	size_t	i;
	Array<double>	d(3);

	printTitle("Test type double");

	i = 0;
	while (i < d.size())
	{
		d[i] = 3.3 * (double)i;
		i++;
	}
	i = 0;
	while (i < d.size())
	{
		std::cout << "d[" << i << "] = " << d[i] << std::endl;
		i++;
	}
}

static void	testTypeString()
{
	Array<std::string>	s(2);

	printTitle("Test type std::string");
	
	s[0] = "42";
	s[1] = "CPP07";
	std::cout << "s[0] = " << s[0] << std::endl;
	std::cout << "s[1] = " << s[1] << std::endl;
}

static void	testSubjectHint()
{
	int	*a = new int();

	printTitle("Subject hint: value-initialization");

	std::cout << "*a = " << *a << " (should be 0)" << std::endl;
	delete a;
}

int	main(void)
{
	testDefaultConstructor();
	std::cout << std::endl;
	testConstructorWithSize();
	std::cout << std::endl;
	testConstOperator();
	std::cout << std::endl;
	testCopyConstructor();
	std::cout << std::endl;
	testAssignmentDeepCopy();
	std::cout << std::endl;
	testOutOfBounds();
	std::cout << std::endl;
	testTypeDouble();
	std::cout << std::endl;
	testTypeString();
	std::cout << std::endl;
	testSubjectHint();
	return (0);
}
