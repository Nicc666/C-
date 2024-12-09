/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nspinell <nspinell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 15:44:32 by nspinell          #+#    #+#             */
/*   Updated: 2024/12/07 17:56:54 by nspinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap()
{
    std::cout << "FragTrap default constructor called" << std::endl;
    this->hit_points = 100;
    this->energy = 100;
    this->attack_damage = 30;
}

FragTrap::FragTrap(const std::string &name) : ClapTrap(name)
{
    std::cout << "FragTrap name constructor called" << std::endl;
    this->hit_points = 100;
    this->energy = 100;
    this->attack_damage = 30;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
    std::cout << "FragTrap copy constructor called" << std::endl;
    *this = other;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap distructor called" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other)
{
    std::cout << "FragTrap copy operator called" << std::endl;
    ClapTrap::operator=(other);
    return (*this);
}

void FragTrap::attack(const std::string &target)
{
    if (this->hit_points == 0 || this->energy == 0)
    {
        std::cout << "FragTrap " << this->name << " impossible to attack, not enough points" << std::endl;
        return ;
    }
    this->energy -= 1;
    std::cout << "FragTrap " << this->name << " attacks " << target \
    << " causing " << this->attack_damage << " points of damage!" << std::endl;
    return ;
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap " << this->name << " High fives request!" << std::endl;
    return ;
}
