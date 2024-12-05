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

Point::Point(float const a, float const b) : x(Fixed(a)), y(Fixed(b))
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
