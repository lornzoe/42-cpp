/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyanga <lyanga@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 06:49:31 by lyanga            #+#    #+#             */
/*   Updated: 2026/03/24 06:51:23 by lyanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>

class Zombie {
public:
    Zombie(void);
    Zombie(std::string name);
    ~Zombie(void);

    void announce(void);
    void setName(std::string name);

private:
    std::string _name;
};

#endif