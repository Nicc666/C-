/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nspinell <nspinell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 15:45:25 by nspinell          #+#    #+#             */
/*   Updated: 2024/10/19 17:50:23 by nspinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

static double area( Point const a, Point const b, Point const c)
{
    double A;
    double f;

    Fixed x((b.getX() - a.getX())*(c.getY() - a.getY()) - (c.getX() - a.getX())*(b.getY() - a.getY()));
    f = static_cast<double>(x.toFloat());
    A = ((0.5) * fabs(f));
    return (A);
}

bool bsp( Point const a, Point const b, Point const c, Point const p)
{
    double A, A1, A2, A3;
    double e = 0.01;

    A = area(a, b, c);
    A1 = area(a, b, p);
    A2 = area(a, p, c);
    A3 = area(p, b ,c);
    if (A1 == 0 || A2 == 0 || A3 == 0)
        return (false);
    //std::cout << "A: " << A << std::endl << "A1: " << A1 << std::endl << "A2: " << A2 << std::endl << "A3: " << A3 << std::endl;
    //std::cout << "A1 + A2 + A3: " << A1 + A2 + A3 << std::endl;
    if (A - (A1 + A2 + A3) < e)
        return (true);
    else
        return (false);
}

/*
bool bsp( Point const a, Point const b, Point const c, Point const p)
{
    double A, A1, A2, A3;
    double f, f1, f2, f3;

    Fixed x((b.getX() - a.getX())*(c.getY() - a.getY()) - (c.getX() - a.getX())*(b.getY() - a.getY()));
    f = static_cast<double>(x.toFloat());
    A = ((0.5) * fabs(f));

    Fixed x1((b.getX() - a.getX())*(p.getY() - a.getY()) - (p.getX() - a.getX())*(b.getY() - a.getY()));
    f1 = static_cast<double>(x1.toFloat());
    A1 = ((0.5) * fabs(f1));

    Fixed x2((p.getX() - a.getX())*(c.getY() - a.getY()) - (c.getX() - a.getX())*(p.getY() - a.getY()));
    f2 = static_cast<double>(x2.toFloat());
    A2 = ((0.5) * fabs(f2));

    Fixed x3((b.getX() - p.getX())*(c.getY() - p.getY()) - (c.getX() - p.getX())*(b.getY() - p.getY()));
    f3 = static_cast<double>(x3.toFloat());
    A3 = ((0.5) * fabs(f3));

    if (A1 == 0 || A2 == 0 || A3 == 0)
        return (false);
    std::cout << "A: " << A << std::endl << "A1: " << A1 << std::endl << "A2: " << A2 << std::endl << "A3: " << A3 << std::endl;
    std::cout << "A1 + A2 + A3: " << A1 + A2 + A3 << std::endl;
    if (A == roundf(A1 + A2 + A3))
        return (true);
    else
        return (false);
}*/