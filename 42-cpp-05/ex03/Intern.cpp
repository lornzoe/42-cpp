/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyanga <lyanga@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 07:08:06 by lyanga            #+#    #+#             */
/*   Updated: 2026/05/07 17:46:33 by lyanga           ###   ########.fr       */
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
	int i = 0;

	while (i < 3 && formName != forms[i])
		i++;

	switch (i)
	{
		case 0:
			return (new PresidentialPardon(target));
		case 1:
			return (new RobotomyRequestForm(target));
		case 2:
			return (new ShrubberyCreationForm(target));
		default:
			throw Intern::UnknownFormException();
	}
}

const char	*Intern::UnknownFormException::what(void) const throw()
{
	return ("Unknown form type");
}
