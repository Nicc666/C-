/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nspinell <nspinell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 15:42:00 by nspinell          #+#    #+#             */
/*   Updated: 2024/10/19 15:42:02 by nspinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void	Zombie::announce(void)
{
	std::cout << this->name << ": " << "BraiiiiiiinnnzzzZ..." << std::endl;
} 

Zombie::Zombie(std::string ssname)
{
	this->name = ssname;
}

Zombie::~Zombie()
{
	std::cout << this->name << ": " << "dead" << std::endl;
}
