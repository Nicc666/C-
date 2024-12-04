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
		Fixed				&operator=(const Fixed &other);
		bool				operator>(const Fixed &other);
		bool				operator<(const Fixed &other);
		bool				operator>=(const Fixed &other);
		bool				operator<=(const Fixed &other);
		bool				operator==(const Fixed &other);
		bool				operator!=(const Fixed &other);
		Fixed				operator+(const Fixed &other);
		Fixed				operator-(const Fixed &other);
		Fixed				operator*(const Fixed &other);
		Fixed				operator/(const Fixed &other);
		Fixed				&operator++(void);
		Fixed				operator++(int x);
		Fixed				&operator--(void);
		Fixed				operator--(int x);
		static Fixed		&min(Fixed &a, Fixed &b);
		static const Fixed	&min(const Fixed &a, const Fixed &b);
		static Fixed		&max(Fixed &a, Fixed &b);
		static const Fixed	&max(const Fixed &a, const Fixed &b);
		int 				getRawBits( void ) const;
		void 				setRawBits( int const raw );
		int 				toInt( void ) const;
		float 				toFloat( void ) const;
	private:
		int					value;
		static const int	bits = 8;
};

#endif

std::ostream &operator<<(std::ostream& out, const Fixed &other);