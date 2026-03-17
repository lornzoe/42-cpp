/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyanga <lyanga@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 16:02:31 by lyanga            #+#    #+#             */
/*   Updated: 2026/03/17 17:56:14 by lyanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __CONTACT_H__
#define __CONTACT_H__

#include <string>

class Contact
{
	private:
		int			index;
		std::string firstname;
		std::string lastname;
		std::string nickname;
		std::string number;
		std::string secret;

	public:
		Contact(int index,
			std::string first,
			std::string last,
			std::string nick,
			std::string num,
			std::string secret);
		Contact();
		~Contact();
		int getIndex();
		std::string getFirstName();
		std::string	getLastName();
		std::string getNickname();
		std::string getNumber();
		std::string getSecret();
};

#endif