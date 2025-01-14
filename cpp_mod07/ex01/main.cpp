/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nspinell <nspinell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 18:44:32 by nspinell          #+#    #+#             */
/*   Updated: 2025/01/12 19:56:54 by nspinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "iter.hpp"

void increment(int &i)
{
	i = i + 10;
	return;
}

void toupperrr(char &c)
{
	c = c - 32;
	return;
}

int main( void )
{
	int array[5] = {1, 2, 3, 4, 5};
	char *s = new char[20];

	for (int j = 0; j < 20; j++)
	{
		s[j] = 'a' + j;
	}
	s[20] = '\0';
	iter(s, 20, toupperrr);
	std::cout << s << std::endl;
	iter(array, 5, increment);
	for (int i = 0; i < 5; i++)
	{
		std::cout << array[i] << std::endl;
	}
	delete s;
	return 0;
}
