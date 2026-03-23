/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyanga <lyanga@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 06:55:51 by lyanga            #+#    #+#             */
/*   Updated: 2026/03/24 06:55:52 by lyanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point {
public:
    Point(void);
    Point(const float x, const float y);
    Point(const Point& other);
    Point& operator=(const Point& other);
    ~Point(void);

    Fixed getX(void) const;
    Fixed getY(void) const;

private:
    const Fixed _x;
    const Fixed _y;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif