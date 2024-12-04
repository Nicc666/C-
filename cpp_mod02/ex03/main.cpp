/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nspinell <nspinell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 15:45:25 by nspinell          #+#    #+#             */
/*   Updated: 2024/10/19 17:50:23 by nspinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

int main( void )
{    
	Point a(Fixed (1.0f), Fixed (1.0f));
	Point b(Fixed (4.0f), Fixed (1.0f));
	Point c(Fixed (3.0f), Fixed (2.0f));
	Point p1(Fixed (1.0f), Fixed (1.0f));
	Point p2(Fixed (1.5f), Fixed (1.1f));
	Point p3(Fixed (2.5f), Fixed (1.0f));

	std::cout << "result: " << bsp(a,b,c,p1) << std::endl;
	std::cout << "result: " << bsp(a,b,c,p2) << std::endl;
	std::cout << "result: " << bsp(a,b,c,p3) << std::endl;
	return 0;
}
