/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyanga <lyanga@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 15:55:53 by lyanga            #+#    #+#             */
/*   Updated: 2026/04/06 10:01:54 by lyanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __PHONEBOOK_H__
#define __PHONEBOOK_H__

#include "Contact.hpp"

class PhoneBook
{
	private:
		Contact contacts[8];
		int	highestIndex;
	public:
		PhoneBook();
		~PhoneBook();
		void add();
		void search();
};

#endif
