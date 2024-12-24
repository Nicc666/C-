/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nspinell <nspinell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 15:44:32 by nspinell          #+#    #+#             */
/*   Updated: 2024/12/19 17:56:54 by nspinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
	try
	{
		Bureaucrat b("primo", 149);
		//Bureaucrat x("io", 152);
		//Bureaucrat y(x);

		std::cout << b << std::endl;
		std::cout << b.getName() << " " << b.getGrade() << std::endl;
		b.decrement();
		std::cout << b.getName() << " " << b.getGrade() << std::endl;
		Bureaucrat c(b);
		std::cout << c.getName() << " " << c.getGrade() << std::endl;
		c.increment();
		std::cout << c.getName() << " " << c.getGrade() << std::endl;
		Bureaucrat d;
		d = c;
		std::cout << d.getName() << " " << d.getGrade() << std::endl;
		d.decrement();
		std::cout << d.getName() << " " << d.getGrade() << std::endl;
		d.decrement();
		std::cout << d.getName() << " " << d.getGrade() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception called: " << e.what() << std::endl;
	}
	return(0);
}
