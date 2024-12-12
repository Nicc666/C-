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

#include "ClapTrap.hpp"

int main()
{
	ClapTrap clap1("Ciccio");
	ClapTrap clap2("Pasticco");
	ClapTrap copyclap(clap1);

	clap1.attack("Pasticcio");
	clap2.takeDamage(5);
	clap1.attack("Pasticcio");
	clap2.takeDamage(100);
	clap2.attack("Ciccio");
	clap1.beRepaired(5);
	clap2.beRepaired(5);
	copyclap.attack("Pasticcio");
	return (0);
}
