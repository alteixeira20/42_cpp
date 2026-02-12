/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alteixeira20 <paalexan@student.42porto.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 14:04:08 by alteixeira20      #+#    #+#             */
/*   Updated: 2026/02/11 14:17:20 by alteixeira20     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"

static void	printTitle(const std::string &title)
{
	std::cout << "-> " << title << std::endl;
}

static void	testingIncrement(Bureaucrat &bureaucrat)
{
	printTitle("Testing Increment - expected grade 9");

	bureaucrat.incrementGrade();
	std::cout << bureaucrat << std::endl;
	std::cout << std::endl;

}
static void	testingDecrement(Bureaucrat &bureaucrat)
{
	int	i;

	printTitle("Testing Decrement - expected grade 20");
	i = 0;
	while (i < 11)
	{
		bureaucrat.decrementGrade();
		i++;
	}
	std::cout << bureaucrat << std::endl;
	std::cout << std::endl;
}

static void	testingHighGrade()
{
	printTitle("Testing High Grade Exception");
	try
	{
		Bureaucrat	test_high("42 High", 0);
		std::cout << test_high << std::endl;
		test_high.incrementGrade();
		std::cout << test_high << std::endl;
		test_high.decrementGrade();
		std::cout << test_high << std::endl;
	}
	catch (const Bureaucrat::GradeTooHighException &except)
	{
		std::cout << except.what() << std::endl;
	}
	std::cout << std::endl;
}

static void	testingLowGrade()
{
	printTitle("Testing Low Grade Exception");
	try
	{
		Bureaucrat	test_low("42 Low", 151);
		std::cout << test_low << std::endl;
		test_low.decrementGrade();
		std::cout << test_low << std::endl;
		test_low.incrementGrade();
		std::cout << test_low << std::endl;
	}
	catch (const Bureaucrat::GradeTooLowException &except)
	{
		std::cout << except.what() << std::endl;
	}
	std::cout << std::endl;
}

static void	testingIncrementLimit()
{
	printTitle("Testing Increment at grade 1 (should throw)");
	try
	{
		Bureaucrat	top("Top", 1);
		std::cout << top << std::endl;
		top.incrementGrade();
	}
	catch (const Bureaucrat::GradeTooHighException &except)
	{
		std::cout << except.what() << std::endl;
	}
	std::cout << std::endl;
}

static void	testingDecrementLimit()
{
	printTitle("Testing Decrement at grade 150 (should throw)");
	try
	{
		Bureaucrat	bottom("Bottom", 150);
		std::cout << bottom << std::endl;
		bottom.decrementGrade();
	}
	catch (const Bureaucrat::GradeTooLowException &except)
	{
		std::cout << except.what() << std::endl;
	}
	std::cout << std::endl;
}

static void	testingCopyAndAssign()
{
	printTitle("Testing Copy Constructor and Assignment");
	Bureaucrat	original("Original", 42);
	Bureaucrat	copy(original);
	Bureaucrat	assigned("Assigned", 100);

	assigned = original;
	std::cout << original << std::endl;
	std::cout << copy << std::endl;
	std::cout << assigned << std::endl;
	std::cout << std::endl;
}
int	main()
{
	/** Default Constructor **/
	printTitle("Constructor Section");
	Bureaucrat	test_default;
	Bureaucrat	test_custom("42 Student", 10);
	std::cout << test_custom << std::endl;
	std::cout << std::endl;

	/** Testing **/
	testingIncrement(test_custom);
	testingDecrement(test_custom);
	testingHighGrade();
	testingLowGrade();
	testingIncrementLimit();
	testingDecrementLimit();
	testingCopyAndAssign();

	/*
	 * Destructor Order
	 *
	 * Expected order:
	 * 	test_custom (grade 20)
	 * 	test_default (grade 42)
	 *
	 * Note: All objects created inside the testing functions are
	 * destroyed when those functions return.
	*/
	printTitle("Destructor Section");

	return (0);
}
