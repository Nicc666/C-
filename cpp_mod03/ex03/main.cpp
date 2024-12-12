/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nspinell <nspinell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 15:44:32 by nspinell          #+#    #+#             */
/*   Updated: 2024/12/07 17:56:54 by nspinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main()
{
	FragTrap clap1("Ciccio");
	ScavTrap scav("scavino");
	DiamondTrap D("dia");
	
	std::cout << "ScavTrap param : " << scav.getAttackDamage() << " " << scav.getEnergy() << " " << scav.getHitPoints() << std::endl;
	std::cout << "FragTrap param : " << clap1.getAttackDamage() << " " << clap1.getEnergy() << " " << clap1.getHitPoints() << std::endl;
	std::cout << "DiamondTrap param : " << D.getAttackDamage() << " " << D.getEnergy() << " " << D.getHitPoints() << std::endl;
	scav.attack("Pasticcio");
	D.attack("Pasticcio");
	D.whoAmI();
	return (0);
}
