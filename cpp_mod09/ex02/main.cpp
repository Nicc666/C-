/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nspinell <nspinell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 12:44:32 by nspinell          #+#    #+#             */
/*   Updated: 2025/01/29 12:56:54 by nspinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	if (argc < 3)
	{
		std::cout << "Error: number of arguments" << std::endl;
		return 1;
	}
	if (PmergeMe::inputerror(argv) == false)
	{
		std::cout << "Error: provide a correct list of numbers" << std::endl;
		return 1;
	}
	PmergeMe pm;
	if (!pm.sort(argv))
		return 1;
	return 0;
}
