/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nspinell <nspinell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 15:44:32 by nspinell          #+#    #+#             */
/*   Updated: 2024/12/07 17:56:54 by nspinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
    std::cout << "ClapTrap default constructor called" << std::endl;
    this->name = "";
    this->hit_points = 10;
    this->energy = 10;
    this->attack_damage = 0;
}

ClapTrap::ClapTrap(const std::string &name)
{
    std::cout << "ClapTrap name constructor called" << std::endl;
    this->name = name;
    this->hit_points = 10;
    this->energy = 10;
    this->attack_damage = 0;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
    std::cout << "ClapTrap copy constructor called" << std::endl;
    *this = other;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap distructor called" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
    std::cout << "ClapTrap copy operator called" << std::endl;
    this->name = other.getName();
    this->hit_points = other.getHitPoints();
    this->energy = other.getEnergy();
    this->attack_damage = other.getAttackDamage();
    return (*this);
}

std::string ClapTrap::getName() const
{
    return (this->name);
}

unsigned int ClapTrap::getHitPoints() const
{
    return (this->hit_points);
}

unsigned int ClapTrap::getEnergy() const
{
    return (this->energy);
}

unsigned int ClapTrap::getAttackDamage() const
{
    return (this->attack_damage);
}

void ClapTrap::attack(const std::string &target)
{
    if (this->hit_points == 0 || this->energy == 0)
    {
        std::cout << "ClapTrap " << this->name << " impossible to attack, not enough points" << std::endl;
        return ;
    }
    this->energy -= 1;
    std::cout << "ClapTrap " << this->name << " attacks " << target \
    << " causing " << this->attack_damage << " points of damage!" << std::endl;
    return ;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (this->hit_points == 0)
    {
        std::cout << "ClapTrap " << this->name << " stop, stop, it's already dead" << std::endl;
        return ;
    }
    if (amount >= this->hit_points)
    {
        std::cout << "ClapTrap " << this->name << " has taken " << amount << " damage ,is dead" << std::endl;
        this->hit_points = 0;
        return ;
    }
    this->hit_points -= amount;
    std::cout << "ClapTrap " << this->name << " taken damage of " << amount \
    << " ,now remain " << this->hit_points << std::endl;
    return ;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (this->hit_points == 0 || this->energy == 0)
    {
        std::cout << "ClapTrap " << this->name << " impossible repair, not enough points or already dead" << std::endl;
        return ;
    }
    this->hit_points += amount;
    this->energy -= 1;
    std::cout << "ClapTrap " << this->name << " repairs itself of " << amount \
    << " now has " << this->hit_points << " hit points" << std::endl;
    return ;
}
