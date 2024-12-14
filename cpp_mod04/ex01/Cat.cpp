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

Cat::Cat()
{
    std::cout << "(Cat) Default constructor called" << std::endl;
    this->type = "Cat";
    brain = new Brain();
}

Cat::Cat(const Cat &other) : Animal(other)
{
    std::cout << "(Cat) Copy constructor called" << std::endl;
    *this = other;
}

Cat &Cat::operator=(const Cat &other)
{
    std::cout << "(Cat) Copy operator" << std::endl;
    this->type = "Cat";
    brain = new Brain(*other.brain);
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

void Cat::set_idea(int i, std::string s)
{
    this->brain->set_idea(i, s);
    return;
}

std::string Cat::get_idea(int i) const
{
    return(brain->get_idea(i));
}
