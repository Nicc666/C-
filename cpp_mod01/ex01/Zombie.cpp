/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nspinell <nspinell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 15:43:54 by nspinell          #+#    #+#             */
/*   Updated: 2024/10/19 15:43:56 by nspinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void	Zombie::announce(void)
{
	std::cout << name << ": " << "BraiiiiiiinnnzzzZ..." << std::endl;
} 

Zombie::Zombie(std::string ssname)
{
	name = ssname;
}

Zombie::Zombie()
{
}

Zombie::~Zombie()
{
	std::cout << name << ": " << "dead" << std::endl;
}

void	Zombie::nameset(std::string ssname)
{
	name = ssname;
}
 