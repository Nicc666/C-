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

#include "RPN.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Error: arg numbers" << std::endl;
		return(1);
	}
	std::string s(argv[1]);
	if (RPN::inputerror(s) == false)
	{
		std::cout << "Error: invalid character in input" << std::endl;
		return(1);
	}
	RPN rpn;
	try
	{
		rpn.rpn(s);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
		return(1);
	}
	return 0;
}
