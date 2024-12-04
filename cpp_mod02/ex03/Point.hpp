/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nspinell <nspinell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 15:44:39 by nspinell          #+#    #+#             */
/*   Updated: 2024/10/19 17:25:37 by nspinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point
{
	public:
		Point();
		Point(Fixed const a, Fixed const b);
		Point(Point const &other);
		~Point();
		Point	&operator=(const Point &other);
		Fixed	getX() const;
		Fixed	getY() const;
	private:
		Fixed const	x;
		Fixed const	y;
};

#endif

bool bsp( Point const a, Point const b, Point const c, Point const p);
