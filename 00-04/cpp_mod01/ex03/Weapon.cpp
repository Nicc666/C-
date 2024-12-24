/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nspinell <nspinell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 15:45:11 by nspinell          #+#    #+#             */
/*   Updated: 2024/10/19 15:45:12 by nspinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string ty)
{
	this->type = ty;
}

Weapon::~Weapon()
{
}

const std::string &Weapon::getType()
{
	return(this->type);
}

void Weapon::setType(std::string newtype)
{
	this->type = newtype;
	return ;
}