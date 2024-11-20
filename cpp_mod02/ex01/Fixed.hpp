/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nspinell <nspinell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 15:44:39 by nspinell          #+#    #+#             */
/*   Updated: 2024/10/19 17:25:37 by nspinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <string>
#include <iostream>
#include <cmath>

class Fixed
{
	public:
		Fixed();
		Fixed(const Fixed &other);
		Fixed(const int x);
		Fixed(const float x);
		~Fixed();
		Fixed	&operator=(const Fixed &other);
		int getRawBits( void ) const;
		void setRawBits( int const raw );
		int toInt( void ) const;
		float toFloat( void ) const;
	private:
		int value;
		static const int bits = 8;
};

#endif

std::ostream &operator<<(std::ostream& out, const Fixed &other);