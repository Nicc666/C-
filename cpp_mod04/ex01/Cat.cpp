/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nspinell <nspinell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 15:44:32 by nspinell          #+#    #+#             */
/*   Updated: 2024/12/07 17:56:54 by nspinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
    std::cout << "(Cat) Default constructor called" << std::endl;
    brain = new Brain();
}

Cat::Cat(const Cat &other) : Animal("Cat")
{
    std::cout << "(Cat) Copy constructor called" << std::endl;
    *this = other;
}

Cat &Cat::operator=(const Cat &other)
{
    std::cout << "(Cat) Copy operator" << std::endl;
    this->type = other.type;
    this->brain = other.brain;
    return(*this);
}

Cat::~Cat()
{
    std::cout << "(Cat) Default distructor called" << std::endl;
    delete brain;
}

void Cat::makeSound(void) const
{
    std::cout << "Miao miao" << std::endl;
}
