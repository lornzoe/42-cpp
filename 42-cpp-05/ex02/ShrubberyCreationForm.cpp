/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyanga <lyanga@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 07:07:11 by lyanga            #+#    #+#             */
/*   Updated: 2026/04/06 19:24:48 by lyanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
	: AForm("Shrubbery Creation", 145, 137), _target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src)
	: AForm(src), _target(src._target)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs)
{
	AForm::operator=(rhs);
	_target = rhs._target;
	return (*this);
}

void	ShrubberyCreationForm::action(void) const
{
	std::string filename = _target + "_shrubbery";
	std::ofstream file(filename.c_str());
	if (!file.is_open())
	{
		std::cerr << "Could not create file " << filename << std::endl;
		return;
	}
	file << "                                  ___" << std::endl;
	file << "                                 (o o)" << std::endl;
	file << "                                (  =  )" << std::endl;
	file << "                               (        )" << std::endl;
	file << "                              (           )" << std::endl;
	file << "                             (              )" << std::endl;
	file << "                            (__________________)" << std::endl;
	file.close();
	std::cout << "Shrubbery has been planted in " << filename << std::endl;
}
