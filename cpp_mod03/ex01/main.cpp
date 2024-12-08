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

int main()
{
    ScavTrap *scav2 = new ScavTrap("nuovo");
    ScavTrap scav("scavino");
    ClapTrap clap1("Ciccio");
    ClapTrap clap2("Pasticcio");
    

    clap1.attack("Pasticcio");
    clap2.takeDamage(5);
    clap1.attack("Pasticcio");
    clap2.takeDamage(100);
    clap2.attack("Ciccio");
    clap1.beRepaired(5);
    clap2.beRepaired(5);

    scav.guardGate();
    scav.attack("Ciccio");
    scav.takeDamage(5);
    scav.beRepaired(5);
    scav2->attack("Ciccio");
    delete scav2;
    return (0);
}
