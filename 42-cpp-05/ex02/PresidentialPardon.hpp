/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardon.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyanga <lyanga@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 07:07:03 by lyanga            #+#    #+#             */
/*   Updated: 2026/03/24 07:08:38 by lyanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDON_HPP
#define PRESIDENTIALPARDON_HPP

#include "AForm.hpp"
#include <string>

class PresidentialPardon : public AForm
{
private:
	std::string	_target;

	PresidentialPardon(void);

public:
	PresidentialPardon(const std::string &target);
	PresidentialPardon(const PresidentialPardon &src);
	~PresidentialPardon(void);

	PresidentialPardon	&operator=(const PresidentialPardon &rhs);

	virtual void	action(void) const;
};

#endif
