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
		std::cout << "Error: provide a list of numbers" << std::endl;
		return 1;
	}
	PmergeMe pm;
	pm.algoritm(argv);
	return 0;
}
