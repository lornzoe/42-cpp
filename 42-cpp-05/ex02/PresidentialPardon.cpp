/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardon.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyanga <lyanga@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 07:07:01 by lyanga            #+#    #+#             */
/*   Updated: 2026/03/24 07:08:38 by lyanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardon.hpp"
#include <iostream>

PresidentialPardon::PresidentialPardon(const std::string &target)
	: AForm("Presidential Pardon", 25, 5), _target(target)
{
}

PresidentialPardon::PresidentialPardon(const PresidentialPardon &src)
	: AForm(src), _target(src._target)
{
}

PresidentialPardon::~PresidentialPardon(void)
{
}

PresidentialPardon	&PresidentialPardon::operator=(const PresidentialPardon &rhs)
{
	AForm::operator=(rhs);
	_target = rhs._target;
	return (*this);
}

void	PresidentialPardon::action(void) const
{
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
