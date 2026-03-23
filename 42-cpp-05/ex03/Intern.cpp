/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyanga <lyanga@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 07:08:06 by lyanga            #+#    #+#             */
/*   Updated: 2026/03/24 07:08:38 by lyanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "PresidentialPardon.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

Intern::Intern(void)
{
}

Intern::Intern(const Intern &src)
{
	(void)src;
}

Intern::~Intern(void)
{
}

Intern	&Intern::operator=(const Intern &rhs)
{
	(void)rhs;
	return (*this);
}

AForm	*Intern::makeForm(const std::string &formName, const std::string &target)
{
	const std::string forms[3] = {
		"presidential pardon",
		"robotomy request",
		"shrubbery creation"
	};

	for (int i = 0; i < 3; i++)
	{
		if (formName == forms[i])
		{
			if (i == 0)
				return (new PresidentialPardon(target));
			else if (i == 1)
				return (new RobotomyRequestForm(target));
			else
				return (new ShrubberyCreationForm(target));
		}
	}
	throw Intern::UnknownFormException();
}

const char	*Intern::UnknownFormException::what(void) const throw()
{
	return ("Unknown form type");
}
