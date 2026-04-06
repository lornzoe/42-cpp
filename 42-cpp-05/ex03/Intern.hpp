/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyanga <lyanga@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 07:08:09 by lyanga            #+#    #+#             */
/*   Updated: 2026/04/06 19:24:49 by lyanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include <string>

class Intern
{
public:
	Intern(void);
	Intern(const Intern &src);
	~Intern(void);

	Intern	&operator=(const Intern &rhs);

	AForm	*makeForm(const std::string &formName, const std::string &target);

	class UnknownFormException : public std::exception
	{
	public:
		virtual const char	*what(void) const throw();
	};
};

#endif
