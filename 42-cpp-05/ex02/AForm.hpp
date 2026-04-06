/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyanga <lyanga@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 07:06:43 by lyanga            #+#    #+#             */
/*   Updated: 2026/04/06 19:24:47 by lyanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <iostream>
#include <exception>

class Bureaucrat;

class AForm
{
private:
	const std::string	_name;
	bool				_signed;
	const int			_gradeToSign;
	const int			_gradeToExecute;

	AForm(void);

public:
	AForm(const std::string &name, int gradeToSign, int gradeToExecute);
	AForm(const AForm &src);
	virtual ~AForm(void);

	AForm	&operator=(const AForm &rhs);

	const std::string	&getName(void) const;
	bool				isSigned(void) const;
	int					getGradeToSign(void) const;
	int					getGradeToExecute(void) const;

	void	beSigned(const Bureaucrat &b);
	void	execute(const Bureaucrat &b) const;
	virtual void	action(void) const = 0;

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

	class FormNotSignedException : public std::exception
	{
	public:
		virtual const char	*what(void) const throw();
	};
};

std::ostream	&operator<<(std::ostream &o, const AForm &f);

#endif
