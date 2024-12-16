/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nspinell <nspinell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 15:44:32 by nspinell          #+#    #+#             */
/*   Updated: 2024/12/07 17:56:54 by nspinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() : name("")
{
    for (int i = 0; i < 4; i++)
        inventory[i] = NULL;
}

Character::Character(std::string const &name) : name(name)
{
    for (int i = 0; i < 4; i++)
        inventory[i] = NULL;
}

Character::Character(Character const &other)
{
    *this = other;
}

Character &Character::operator=(Character const &other)
{
    int i = 0;
    this->name = other.name;
    for (i = 0; i < 4; i++)
    {
        if (this->inventory[i] != NULL)
        {
            delete this->inventory[i];
            this->inventory[i] = NULL;
        }
    }
    for (i = 0; i < 4; i++)
    {
        if (other.inventory[i] != NULL)
            this->inventory[i] = other.inventory[i]->clone();
        else
            this->inventory[i] = NULL;
    }
    return (*this);
}

Character::~Character()
{
    for (int i = 0; i < 4; i++)
    {
        if (this->inventory[i] != NULL)
            delete this->inventory[i];
    }
}

std::string const &Character::getName() const
{
    return (this->name);
}

void Character::equip(AMateria* m)
{
    if (m == NULL)
        return;
    for (int i = 0; i < 4; i++)
    {
        if (this->inventory[i] == NULL)
        {
            this->inventory[i] = m->clone();
            return;
        }
    }
    std::cout << "Inventory full" << std::endl;
    return;
}

void Character::unequip(int idx)
{
    if (idx < 0 || idx > 3)
        return;
    this->inventory[idx] = NULL;
    return;
}

void Character::use(int idx, ICharacter &target)
{
    if (idx < 0 || idx > 3)
        return;
    if (this->inventory[idx] == NULL)
        return;
    this->inventory[idx]->use(target);
    return;
}
