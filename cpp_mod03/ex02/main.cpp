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

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
    ScavTrap *scav2 = new ScavTrap("nuovo");
    ScavTrap scav("scavino");
    ClapTrap clap1("Ciccio");
    FragTrap ff;
    FragTrap frag("Frag");
    
    clap1.attack("Pasticcio");
    clap1.attack("Pasticcio");
    clap1.beRepaired(5);

    scav.guardGate();
    scav.attack("Ciccio");
    scav2->attack("Ciccio");

    frag.attack("Ciccio");
    frag.highFivesGuys();
    std::cout << frag.getAttackDamage() << std::endl;
    std::cout << frag.getEnergy() << std::endl;;
    std::cout << frag.getHitPoints() << std::endl;;
    delete scav2;
    return (0);
}
