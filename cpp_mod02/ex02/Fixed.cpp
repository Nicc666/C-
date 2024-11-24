/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nspinell <nspinell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 15:44:32 by nspinell          #+#    #+#             */
/*   Updated: 2024/10/19 17:56:54 by nspinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
    std::cout << "Default constructor called" << std::endl;
	this->value = 0;
	return;
}

Fixed::Fixed(const Fixed &other)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
    return;
}

Fixed::Fixed(const int x)
{
    std::cout << "Int constructor called" << std::endl;
    this->value = (x << 8);
    return;
}

Fixed::Fixed(const float x)
{
    std::cout << "Float constructor called" << std::endl;
    this->value = (int)(roundf(x * 256));
    return;
}

Fixed &Fixed::operator=(const Fixed &other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
    {
        this->value = other.getRawBits();
    }
    return (*this);
}

bool Fixed::operator>(const Fixed &other)
{
    if (this->value > other.getRawBits())
        return(true);
    else
        return(false);
}

bool Fixed::operator<(const Fixed &other)
{
    if (this->value < other.getRawBits())
        return(true);
    else
        return(false);
}

bool Fixed::operator>=(const Fixed &other)
{
    if (this->value >= other.getRawBits())
        return(true);
    else
        return(false);
}

bool Fixed::operator<=(const Fixed &other)
{
    if (this->value <= other.getRawBits())
        return(true);
    else
        return(false);
}

bool Fixed::operator==(const Fixed &other)
{
    if (this->value == other.getRawBits())
        return(true);
    else
        return(false);
}

bool Fixed::operator!=(const Fixed &other)
{
    if (this->value != other.getRawBits())
        return(true);
    else
        return(false);
}

Fixed Fixed::operator+(const Fixed &other)
{
    Fixed r;

    r.setRawBits(this->value + other.getRawBits());
    return(r);
}

Fixed Fixed::operator-(const Fixed &other)
{
    Fixed r;

    r.setRawBits(this->value - other.getRawBits());
    return(r);
}

Fixed Fixed::operator*(const Fixed &other)
{
    Fixed r;

    r.setRawBits((this->toFloat() * other.toFloat()) * 256);
    return(r);
}

Fixed Fixed::operator/(const Fixed &other)
{
    Fixed r;

    r.setRawBits((this->toFloat() / other.toFloat()) * 256);
    return(r);
}

std::ostream &operator<<(std::ostream &out, const Fixed &other)
{
    out << other.toFloat();
    return (out);
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
    return;
}

int Fixed::getRawBits( void ) const
{
    return (this->value);
}

void Fixed::setRawBits( int const raw )
{
    this->value = raw;
    return;
}

int Fixed::toInt( void ) const
{
    int r = this->value >> 8;
    return (r);
}

float Fixed::toFloat( void ) const
{
    float b = this->value / 256.0;
    return (b);
}
