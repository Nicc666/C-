/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nspinell <nspinell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 15:44:48 by nspinell          #+#    #+#             */
/*   Updated: 2024/10/19 15:44:51 by nspinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string nam): name(nam), weapon(NULL) 
{
}

HumanB::~HumanB()
{
}

void HumanB::attack()
{
    if (weapon == NULL)
        return ;
    std::cout << name << " attacks with their " << weapon->getType() << std::endl;
    return ;
}

void HumanB::setWeapon(Weapon &wea)
{
    weapon = &wea;
    return ;
}