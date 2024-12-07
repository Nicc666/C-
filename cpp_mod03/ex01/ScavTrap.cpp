/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nspinell <nspinell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 15:44:32 by nspinell          #+#    #+#             */
/*   Updated: 2024/12/07 17:56:54 by nspinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
    std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name)
{
    std::cout << "ScavTrap name constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
    std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap distructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
    std::cout << "ScavTrap copy operator called" << std::endl;
    ClapTrap::operator=(other);
    return (*this);
}

void ScavTrap::attack(const std::string &target)
{
    if (ClapTrap::getHitPoints() == 0 || ClapTrap::getEnergy() == 0)
    {
        std::cout << "ScavTrap " << ClapTrap::getName() << " impossible to attack, not enough points" << std::endl;
        return ;
    }
    ClapTrap::setEnergy(ClapTrap::getEnergy() - 1);
    std::cout << "ScavTrap " << ClapTrap::getName() << " attacks " << target \
    << " causing " << ClapTrap::getAttackDamage() << " points of damage!" << std::endl;
    return ;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << ClapTrap::getName() << " is now in Gatekeeper mode!" << std::endl;
}
