/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nspinell <nspinell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 12:44:32 by nspinell          #+#    #+#             */
/*   Updated: 2025/01/17 12:56:54 by nspinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <vector>
#include "easyfind.hpp"

int main(int, char**)
{
	int arr[] = {1, 5, 6, 99, 12};
	std::vector<int> v(arr, arr + sizeof(arr) / sizeof(int));
	try
	{
		std::vector<int>::iterator it;
		int y = 12;
		int z = 123;
		it = easyfind(v, 6);
		std::cout << *it << std::endl;
		std::cout << *easyfind(v, y) << std::endl;
		std::cout << *easyfind(v, z) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << "element doesn't find" << std::endl;
	}
	std::cout << "-----------------------------------------------" << std::endl;
	return 0;
}
