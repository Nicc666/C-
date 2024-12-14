/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nspinell <nspinell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 15:44:32 by nspinell          #+#    #+#             */
/*   Updated: 2024/12/07 17:56:54 by nspinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("Animal")
{
    std::cout << "(WrongAnimal) Default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const std::string &type) : type(type)
{
    std::cout << "(WrongAnimal) Type constructor called" << std::endl;
    this->type = type;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other)
{
    std::cout << "(WrongAnimal) Copy constructor called" << std::endl;
    *this = other;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other)
{
    std::cout << "(WrongAnimal) Copy operator" << std::endl;
    this->type = other.type;
    return(*this);
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "(WrongAnimal) Default distructor called" << std::endl;
}

std::string WrongAnimal::getType(void) const
{
    return(this->type);
}

void WrongAnimal::makeSound(void) const
{
    std::cout << "No sound" << std::endl;
}
