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
	this->value = 0;
	return;
}

Fixed::Fixed(const Fixed &other)
{
    *this = other;
    return;
}

Fixed::Fixed(const int x)
{
    this->value = (x << 8);
    return;
}

Fixed::Fixed(const float x)
{
    this->value = (int)(roundf(x * 256));
    return;
}

Fixed::~Fixed()
{
    return;
}

Fixed &Fixed::operator=(const Fixed &other)
{
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

Fixed &Fixed::operator++(void)
{
    this->setRawBits(this->value + 1);
    return(*this);
}

Fixed Fixed::operator++(int x)
{
    (void)x;
    Fixed t = *this;

    this->setRawBits(this->value + 1);
    return(t);
}

Fixed &Fixed::operator--(void)
{
    this->setRawBits(this->value - 1);
    return(*this);
}

Fixed Fixed::operator--(int x)
{
    (void)x;
    Fixed t = *this;

    this->setRawBits(this->value - 1);
    return(t);
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
    if (a.getRawBits() < b.getRawBits())
        return(a);
    else
        return(b);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
    if (a.getRawBits() < b.getRawBits())
        return(a);
    else
        return(b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
    if (a.getRawBits() > b.getRawBits())
        return(a);
    else
        return(b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
    if (a.getRawBits() > b.getRawBits())
        return(a);
    else
        return(b);
}

std::ostream &operator<<(std::ostream &out, const Fixed &other)
{
    out << other.toFloat();
    return (out);
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
