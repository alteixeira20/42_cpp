/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alteixeira20 <paalexan@student.42porto.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 16:21:08 by alteixeira20      #+#    #+#             */
/*   Updated: 2026/04/09 16:42:49 by alteixeira20     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "RPN.hpp"
# include <sstream>
# include <cctype>

/* Helper Functions */

static bool	isOperator(char c)
{
	if (c == '+' || c == '-' || c == '*' || c == '/')
		return (true);
	else
		return (false);
}

static long	processOperation(long a, long b, char op)
{
	if (op == '+')
		return (a + b);
	if (op == '-')
		return (a - b);
	if (op == '*')
		return (a * b);

	if (b == 0)
		throw RPN::Error("Error");
	if (op == '/')
		return (a / b);
	else
		throw RPN::Error("Error");
}

/* OCF */

RPN::RPN()
{
}

RPN::RPN(const RPN &other)
{
	(void)other;
}

RPN	&RPN::operator=(const RPN &other)
{
	(void)other;
	return (*this);
}

RPN::~RPN()
{
}

/* core */
long	RPN::evaluate(const std::string &expr) const
{
	std::istringstream	iss(expr);
	std::string		token;
	std::stack<long>	stack;

	while (iss >> token)
	{
		// Number token (must be single digit between 0..9)
		if (token.size() == 1 && std::isdigit(static_cast<unsigned char>(token[0])))
			stack.push(static_cast<long>(token[0] - '0'));
		// Operator token (must be either '+', '-',  '*' or '/')
		else if (token.size() == 1 && isOperator(token[0]))
		{
			long	b;
			long	a;
			long	result;

			if (stack.size() < 2)
				throw RPN::Error("Error");
			b = stack.top();
			stack.pop();
			a = stack.top();
			stack.pop();

			result = processOperation(a, b, token[0]);
			stack.push(result);
		}
		else
			throw RPN::Error("Error");
	}
	if (stack.size() != 1)
		throw RPN::Error("Error");
	return (stack.top());
}
