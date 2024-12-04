/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nspinell <nspinell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 15:44:32 by nspinell          #+#    #+#             */
/*   Updated: 2024/10/19 17:56:54 by nspinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : x(0), y(0)
{
}

Point::Point(Fixed const a, Fixed const b) : x(a), y(b)
{
}

Point::Point(Point const &a) : x(a.getX()), y(a.getY())
{
    return;
}

Point &Point::operator=(const Point &other)
{
    (void)other;
    return (*this);
}

Point::~Point()
{
    return;
}

Fixed Point::getX() const
{
    return(x);
}

Fixed Point::getY() const
{
    return(y);
}
