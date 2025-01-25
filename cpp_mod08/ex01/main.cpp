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

#include <string>
#include "Span.hpp"

int main(int, char**)
{
	try
	{
		std::cout << "-----------------------------------------------" << std::endl;
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
		std::cout << "-----------------------------------------------" << std::endl;
		Span s(50000);
		s.addNumber(12);
		s.addNumber(6);
		std::cout << s.getvnum(0) << std::endl;
		std::cout << s.getvnum(1) << std::endl;
		std::cout << "-----------------------------------------------" << std::endl;
		Span sp2(s);
		std::cout << "original vector" << std::endl;
		s.printvector();
		std::cout << "copy vector" << std::endl;
		sp2.printvector();
		std::cout << "-----------------------------------------------" << std::endl;
		std::vector<int> v;
		for (int i = 1; i <= 30000; ++i)
		{
			v.push_back(i);
		}
		sp2.insertmanynum(v);
		sp2.printvector();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return 0;
}
