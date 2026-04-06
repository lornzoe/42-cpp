/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyanga <lyanga@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 16:09:28 by lyanga            #+#    #+#             */
/*   Updated: 2026/04/06 10:02:11 by lyanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(int index,
	std::string first,
	std::string last,
	std::string nick,
	std::string num,
	std::string secret):
	index(index),
	firstname(first),
	lastname(last),
	nickname(nick),
	number(num),
	secret(secret) {}
			
Contact::Contact() {}

Contact::~Contact() {}

std::string Contact::getFirstName()
{
	return Contact::firstname;
}

std::string Contact::getLastName()
{
	return Contact::lastname;
}

std::string Contact::getNickname()
{
	return Contact::nickname;
}

std::string Contact::getNumber()
{
	return Contact::number;
}

std::string Contact::getSecret()
{
	return Contact::secret;
}
