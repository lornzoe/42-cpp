/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyanga <lyanga@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 07:07:11 by lyanga            #+#    #+#             */
/*   Updated: 2026/05/07 17:58:17 by lyanga           ###   ########.fr       */
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
	file << "                     .o00o" << std::endl;
	file << "                   o000000oo" << std::endl;
	file << "                  00000000000o" << std::endl;
	file << "                 00000000000000" << std::endl;
	file << "              oooooo  00000000  o88o" << std::endl;
	file << "           ooOOOOOOOoo  ```''  888888" << std::endl;
	file << "         OOOOOOOOOOOO'.qQQQQq. `8888'" << std::endl;
	file << "        oOOOOOOOOOO'.QQQQQQQQQQ/.88'" << std::endl;
	file << "        OOOOOOOOOO'.QQQQQQQQQQ/ /q" << std::endl;
	file << "         OOOOOOOOO QQQQQQQQQQ/ /QQ" << std::endl;
	file << "           OOOOOOOOO `QQQQQQ/ /QQ'" << std::endl;
	file << "             OO:F_P:O `QQQ/  /Q'" << std::endl;
	file << "                \\\\. \\ |  // |" << std::endl;
	file << "                d\\ \\\\\\|_////" << std::endl;
	file << "                qP| \\\\ _' `|Ob" << std::endl;
	file << "                   \\  / \\  \\Op" << std::endl;
	file << "                   |  | O| |" << std::endl;
	file << "           _       /\\. \\_/ /\\" << std::endl;
	file << "            `---__/|_\\\\   //|  __" << std::endl;
	file << "                  `-'  `-'`-'-'" << std::endl;
	file.close();
	std::cout << "Shrubbery has been planted in " << filename << std::endl;
}
