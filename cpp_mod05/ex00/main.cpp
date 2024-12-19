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
		Bureaucrat b("io", 149);

		std::cout << b << std::endl;
		std::cout << b.getName() << " " << b.getGrade() << std::endl;
		b.decrement();
		std::cout << b.getName() << " " << b.getGrade() << std::endl;
		b.decrement();
		std::cout << b.getName() << " " << b.getGrade() << std::endl;
	}
	catch (const std::exception &exc)
	{
		std::cerr << "Exception called: " << exc.what() << std::endl;
	}
	return(0);
}
