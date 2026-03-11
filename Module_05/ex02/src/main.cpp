/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alteixeira20 <paalexan@student.42porto.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 14:04:08 by alteixeira20      #+#    #+#             */
/*   Updated: 2026/03/11 10:51:20 by alteixeira20     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"
#include "../inc/AForm.hpp"
#include "../inc/PresidentialPardonForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/ShrubberyCreationForm.hpp"
#include <iostream>

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

static void	testNotSignedExecution()
{
	printTitle("Execute without signing (should throw FormNotSigned)");
	try
	{
		Bureaucrat				exec("Exec", 1);
		PresidentialPardonForm	f("Arthur");

		std::cout << exec << std::endl;
		std::cout << f << std::endl;
		exec.executeForm(f);
	}
	catch (const std::exception &e)
	{
		std::cout << "Caught: " << e.what() << std::endl;
	}
	std::cout << std::endl;
}

static void	testExecuteGradeTooLow()
{
	printTitle("Execute with grade too low (should throw GradeTooLow)");
	try
	{
		Bureaucrat				signer("Signer", 1);
		Bureaucrat				lowExec("LowExec", 150);
		RobotomyRequestForm		f("Bender");

		signer.signForm(f);
		std::cout << "Trying to execute with low grade:" << std::endl;
		lowExec.executeForm(f);
	}
	catch (const std::exception &e)
	{
		std::cout << "Caught: " << e.what() << std::endl;
	}
	std::cout << std::endl;
}

static void	testPresidentialHappyPath()
{
	printTitle("PresidentialPardonForm (sign + execute success)");
	try
	{
		Bureaucrat				boss("Boss", 1);
		PresidentialPardonForm	f("Ford");

		std::cout << boss << std::endl;
		std::cout << f << std::endl;
		boss.signForm(f);
		boss.executeForm(f);
	}
	catch (const std::exception &e)
	{
		std::cout << "Unexpected: " << e.what() << std::endl;
	}
	std::cout << std::endl;
}

static void	testRobotomyHappyPath()
{
	printTitle("RobotomyRequestForm (sign + execute, 50% success)");
	try
	{
		Bureaucrat			boss("Boss", 1);
		RobotomyRequestForm	f("Marvin");

		std::cout << boss << std::endl;
		std::cout << f << std::endl;
		boss.signForm(f);

		/* Run twice to better see the randomness */
		boss.executeForm(f);
		boss.executeForm(f);
	}
	catch (const std::exception &e)
	{
		std::cout << "Unexpected: " << e.what() << std::endl;
	}
	std::cout << std::endl;
}

static void	testShrubberyHappyPath()
{
	printTitle("ShrubberyCreationForm (sign + execute creates file)");
	try
	{
		Bureaucrat				boss("Boss", 1);
		ShrubberyCreationForm	f("home");

		std::cout << boss << std::endl;
		std::cout << f << std::endl;
		boss.signForm(f);
		boss.executeForm(f);
		std::cout << "Check file: home_shrubbery" << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Unexpected: " << e.what() << std::endl;
	}
	std::cout << std::endl;
}

static void	testSignGradeTooLow()
{
	printTitle("Sign with grade too low (should throw GradeTooLow)");
	try
	{
		Bureaucrat				lowSigner("LowSigner", 150);
		PresidentialPardonForm	f("Trillian");

		std::cout << lowSigner << std::endl;
		std::cout << f << std::endl;
		lowSigner.signForm(f);
	}
	catch (const std::exception &e)
	{
		std::cout << "Caught: " << e.what() << std::endl;
	}
	std::cout << std::endl;
}

int	main()
{
	/* Default Constructor */
	printTitle("Constructor Section");
	Bureaucrat	test_default;
	Bureaucrat	test_custom("42 Student", 10);
	std::cout << test_custom << std::endl;
	std::cout << std::endl;

	/* Testing */
	testingIncrement(test_custom);
	testingDecrement(test_custom);
	testingHighGrade();
	testingLowGrade();
	testingIncrementLimit();
	testingDecrementLimit();
	testingCopyAndAssign();

	/* Forms Testing */
	testNotSignedExecution();
	testSignGradeTooLow();
	testExecuteGradeTooLow();
	testPresidentialHappyPath();
	testRobotomyHappyPath();
	testShrubberyHappyPath();

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
