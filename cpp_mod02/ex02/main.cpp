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

#include <iostream>
#include "Fixed.hpp"
#include <iomanip>

int main( void )
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	return 0;
}

/*
int main( void )
{
	Fixed a(5.25f);
	Fixed b(10.75f);
	std::cout << "Comparison Operators:" << std::endl;
	std::cout << "a > b: " << (a > b) << std::endl;
	std::cout << "a < b: " << (a < b) << std::endl;
	std::cout << "a >= b: " << (a >= b) << std::endl;
	std::cout << "a <= b: " << (a <= b) << std::endl;
	std::cout << "a == b: " << (a == b) << std::endl;
	std::cout << "a != b: " << (a != b) << std::endl;
	Fixed c(2.5f);
	Fixed d(4.0f);
	std::cout << "Arithmetic Operators:" << std::endl;
	std::cout << "c + d: " << (c + d) << std::endl;
	std::cout << "c - d: " << (c - d) << std::endl;
	std::cout << "c * d: " << (c * d) << std::endl;
	std::cout << "c / d: " << (c / d) << std::endl;
	Fixed e(1.0f);
	std::cout << "Increment and Decrement Operators:" << std::endl;
	std::cout << "e++: " << (e++) << std::setprecision(9) << std::endl;
	std::cout << "After e++: " << e << std::endl;
	Fixed f(3.5f);
	Fixed g(7.25f);
	std::cout << "Static Functions (min and max):" << std::endl;
	std::cout << "min(f, g): " << Fixed::min(f, g) << std::endl;
	std::cout << "max(f, g): " << Fixed::max(f, g) << std::endl;
	return(0);
}*/