/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyanga <lyanga@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 07:06:24 by lyanga            #+#    #+#             */
/*   Updated: 2026/04/06 19:24:46 by lyanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>
#include <exception>

class Bureaucrat;

class Form
{
private:
	const std::string	_name;
	bool				_signed;
	const int			_gradeToSign;
	const int			_gradeToExecute;

	Form(void);

public:
	Form(const std::string &name, int gradeToSign, int gradeToExecute);
	Form(const Form &src);
	~Form(void);

	Form	&operator=(const Form &rhs);

	const std::string	&getName(void) const;
	bool				isSigned(void) const;
	int					getGradeToSign(void) const;
	int					getGradeToExecute(void) const;

	void	beSigned(const Bureaucrat &b);

	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char	*what(void) const throw();
	};

	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char	*what(void) const throw();
	};
};

std::ostream	&operator<<(std::ostream &o, const Form &f);

#endif
