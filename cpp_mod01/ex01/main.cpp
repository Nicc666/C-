/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nspinell <nspinell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 15:42:20 by nspinell          #+#    #+#             */
/*   Updated: 2024/10/19 15:42:23 by nspinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie *z;
	int		i;
	int		N;

	i = 0;
	N = 5;
	z = zombieHorde(N, "KING");
	while (i < N)
	{
		z[i].announce();
		i++;
	}
	delete[] z;
	return(0);
}
