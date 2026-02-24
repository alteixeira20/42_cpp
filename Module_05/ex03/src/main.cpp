/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alteixeira20 <paalexan@student.42porto.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 14:04:08 by alteixeira20      #+#    #+#             */
/*   Updated: 2026/02/24 18:06:43 by alteixeira20     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"
#include "../inc/Intern.hpp"
#include "../inc/AForm.hpp"
#include <iostream>

static void	printTitle(const std::string &title)
{
	std::cout << "-> " << title << std::endl;
}

static void	safeDelete(AForm *form)
{
	if (form != NULL)
		delete form;
}

static void	runSignAndExecute(Bureaucrat &signer, Bureaucrat &executor, AForm *form)
{
	if (form == NULL)
		return ;
	std::cout << *form << std::endl;
	signer.signForm(*form);
	executor.executeForm(*form);
}

static void	runExecuteWithoutSigning(Bureaucrat &executor, AForm *form)
{
	if (form == NULL)
		return ;
	std::cout << *form << std::endl;
	executor.executeForm(*form);
}

static void	scenarioCreateAndRun(Intern &intern, const std::string &formName,
	const std::string &target, Bureaucrat &signer, Bureaucrat &executor,
	const std::string &postNote)
{
	AForm	*form;

	form = NULL;
	try
	{
		form = intern.makeForm(formName, target);
		runSignAndExecute(signer, executor, form);
		if (postNote.empty() == false)
			std::cout << postNote << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Caught: " << e.what() << std::endl;
	}
	safeDelete(form);
}

static void	scenarioUnknownForm(Intern &intern, const std::string &formName,
	const std::string &target)
{
	AForm	*form;

	form = NULL;
	try
	{
		form = intern.makeForm(formName, target);
		std::cout << "Unexpected: Intern created something." << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Caught: " << e.what() << std::endl;
	}
	safeDelete(form);
}

static void	scenarioExecuteWithoutSigning(Intern &intern, const std::string &formName,
	const std::string &target, Bureaucrat &executor)
{
	AForm	*form;

	form = NULL;
	try
	{
		form = intern.makeForm(formName, target);
		runExecuteWithoutSigning(executor, form);
	}
	catch (const std::exception &e)
	{
		std::cout << "Caught: " << e.what() << std::endl;
	}
	safeDelete(form);
}

int	main(void)
{
	Intern		intern;

	Bureaucrat	boss("Boss", 1);
	Bureaucrat	lowSigner("LowSigner", 150);
	Bureaucrat	lowExec("LowExec", 150);

	printTitle("Intern creates known forms (happy path)");
	scenarioCreateAndRun(intern, "presidential pardon", "Ford",
		boss, boss, "");
	scenarioCreateAndRun(intern, "robotomy request", "Marvin",
		boss, boss, "");
	scenarioCreateAndRun(intern, "shrubbery creation", "home",
		boss, boss, "Check file: home_shrubbery");

	printTitle("Intern unknown form name");
	scenarioUnknownForm(intern, "totally random form", "Target");

	printTitle("Execute without signing");
	scenarioExecuteWithoutSigning(intern, "presidential pardon", "Arthur", boss);

	printTitle("Sign grade too low");
	scenarioCreateAndRun(intern, "presidential pardon", "Trillian",
		lowSigner, boss, "");

	printTitle("Execute grade too low (after signing)");
	scenarioCreateAndRun(intern, "robotomy request", "Bender",
		boss, lowExec, "");

	printTitle("Done");
	return (0);
}
