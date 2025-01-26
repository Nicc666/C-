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
		std::cout << "Subject test------------------------------------" << std::endl;
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
		std::cout << "-----------------------------------------------" << std::endl;
		std::cout << "Add number test---------------------------------" << std::endl;
		Span s(50000);
		s.addNumber(12);
		s.addNumber(6);
		std::cout << s.getvnum(0) << std::endl;
		std::cout << s.getvnum(1) << std::endl;
		std::cout << s.getmax() << std::endl;
		s.printvector();
		std::cout << s.shortestSpan() << std::endl;
		std::cout << s.longestSpan() << std::endl;
		std::cout << "Copy costructor test--------------------------------" << std::endl;
		Span sp2(s);
		std::cout << "original vector" << std::endl;
		s.printvector();
		std::cout << "copy vector" << std::endl;
		sp2.printvector();
		std::cout << s.getmax() << std::endl;
		std::cout << sp2.getmax() << std::endl;
		std::cout << "Insert more number test----------------------------------" << std::endl;
		std::vector<int> v;
		for (int i = 1; i <= 70; ++i)
		{
			v.push_back(i);
		}
		sp2.insertmanynum(v);
		sp2.printvector();
		std::cout << sp2.shortestSpan() << std::endl;
		std::cout << sp2.longestSpan() << std::endl;
		std::cout << "Big number number test----------------------------------" << std::endl;
		Span big(10000);
		std::vector<int> vbig;
		for (int i = -100; i <= 9899; ++i)
		{
			vbig.push_back(i);
		}
		big.insertmanynum(vbig);
		//sp2.printvector();
		std::cout << big.shortestSpan() << std::endl;
		std::cout << big.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return 0;
}
