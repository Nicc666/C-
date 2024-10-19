/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nspinell <nspinell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 15:44:08 by nspinell          #+#    #+#             */
/*   Updated: 2024/10/19 15:44:10 by nspinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	Zombie *horde;
	int		i;

	i = 0;
	if (N <= 0)
		return(NULL);
	horde = new Zombie[N];
	while (i < N)
	{
		horde[i].nameset(name);
		i++;
	}
	return(horde);
}
