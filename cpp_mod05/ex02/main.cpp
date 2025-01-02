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
#include "ShrubberyCreationForm.hpp"

int main(void)
{
	try
	{
		Bureaucrat b("bur", 135);
		std::cout << b << std::endl;
		Bureaucrat c("cur", 2);
		std::cout << c << std::endl;
		Bureaucrat d("dur", 150);
		std::cout << d << std::endl;

		ShrubberyCreationForm f("targ_pippo");
		std::cout << f << std::endl;
		std::cout << f.getTarget() << std::endl;
		ShrubberyCreationForm g(f);
		std::cout << g << std::endl;
		std::cout << g.getTarget() << std::endl;
		g.beSigned(b);
		b.executeForm(g);

		g.beSigned(d);
		c.executeForm(f);
		d.executeForm(f);
		std::cout << "-------------------------------------" << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception called: " << e.what() << std::endl;
	}
	return(0);
}
