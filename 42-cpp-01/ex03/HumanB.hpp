/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyanga <lyanga@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 06:50:13 by lyanga            #+#    #+#             */
/*   Updated: 2026/03/24 06:51:23 by lyanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"
# include <string>

class HumanB {
public:
    HumanB(std::string name);
    ~HumanB(void);

    void setWeapon(Weapon& weapon);
    void attack(void);

private:
    std::string _name;
    Weapon* _weapon;
};

#endif