/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nspinell <nspinell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 15:44:32 by nspinell          #+#    #+#             */
/*   Updated: 2024/12/07 17:56:54 by nspinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat()
{
    std::cout << "(WrongCat) Default constructor called" << std::endl;
    this->type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal("WrongCat")
{
    std::cout << "(WrongCat) Copy constructor called" << std::endl;
    *this = other;
}

WrongCat &WrongCat::operator=(const WrongCat &other)
{
    std::cout << "(WrongCat) Copy operator" << std::endl;
    this->type = other.type;
    return(*this);
}

WrongCat::~WrongCat()
{
    std::cout << "(Cat) Default distructor called" << std::endl;
}

void WrongCat::makeSound(void) const
{
    std::cout << "False miao" << std::endl;
}
