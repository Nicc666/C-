/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nspinell <nspinell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 15:44:32 by nspinell          #+#    #+#             */
/*   Updated: 2024/12/07 17:56:54 by nspinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
    std::cout << "(Dog) Default constructor called" << std::endl;
    this->type = "Dog";
    brain = new Brain();
}

Dog::Dog(const Dog &other) : Animal(other)
{
    std::cout << "(Dog) Copy constructor called" << std::endl;
    *this = other;
}

Dog &Dog::operator=(const Dog &other)
{
    std::cout << "(Dog) Copy operator" << std::endl;
    this->type = other.type;
    brain = new Brain(*other.brain);
    return(*this);
}

Dog::~Dog()
{
    std::cout << "(Dog) Default distructor called" << std::endl;
    delete brain;
}

void Dog::makeSound(void) const
{
    std::cout << "Wof wof" << std::endl;
}

void Dog::set_idea(int i, std::string s)
{
    this->brain->set_idea(i, s);
    return;
}

std::string Dog::get_idea(int i) const
{
    return(brain->get_idea(i));
}
