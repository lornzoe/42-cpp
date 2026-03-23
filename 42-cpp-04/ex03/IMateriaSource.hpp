/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyanga <lyanga@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 07:04:40 by lyanga            #+#    #+#             */
/*   Updated: 2026/03/24 07:04:59 by lyanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMATERIALSOURCE_HPP
#define IMATERIALSOURCE_HPP

#include <string>

class AMateria;

class IMateriaSource
{
public:
	virtual ~IMateriaSource() {};

	virtual void learnMateria(AMateria *m) = 0;
	virtual AMateria *createMateria(const std::string &type) = 0;
};

#endif
