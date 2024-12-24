/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nspinell <nspinell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 15:44:32 by nspinell          #+#    #+#             */
/*   Updated: 2024/12/07 17:56:54 by nspinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("Animal")
{
    std::cout << "(Animal) Default constructor called" << std::endl;
}

Animal::Animal(const std::string &type) : type(type)
{
    std::cout << "(Animal) Type constructor called" << std::endl;
}

Animal::Animal(const Animal &other)
{
    std::cout << "(Animal) Copy constructor called" << std::endl;
    *this = other;
}

Animal &Animal::operator=(const Animal &other)
{
    std::cout << "(Animal) Copy operator" << std::endl;
    this->type = other.type;
    return(*this);
}

Animal::~Animal()
{
    std::cout << "(Animal) Default distructor called" << std::endl;
}

std::string Animal::getType(void) const
{
    return(this->type);
}

void Animal::makeSound(void) const
{
    std::cout << "No sound" << std::endl;
}
