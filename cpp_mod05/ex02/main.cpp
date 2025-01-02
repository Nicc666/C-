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
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <ctime>

int main(void)
{
	std::srand(std::time(0));
	try
	{
		std::cout << "FIRST CLASS TRY" << std::endl << std::endl;

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
	try
	{
		std::cout << "SECOND CLASS TRY" << std::endl << std::endl;

		Bureaucrat b("bur", 135);
		std::cout << b << std::endl;
		Bureaucrat c("cur", 2);
		std::cout << c << std::endl;

		RobotomyRequestForm f("rob_pucci");
		std::cout << f << std::endl;
		std::cout << f.getTarget() << std::endl;
	
		RobotomyRequestForm g(f);
		std::cout << g << std::endl;
		std::cout << g.getTarget() << std::endl;
		g.beSigned(c);
		c.executeForm(g);

		f.beSigned(b);
		b.executeForm(f);
		std::cout << "-------------------------------------" << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception called: " << e.what() << std::endl;
	}
	try
	{
		std::cout << "THIRD CLASS TRY" << std::endl << std::endl;

		Bureaucrat b("bur", 135);
		std::cout << b << std::endl;
		Bureaucrat c("cur", 2);
		std::cout << c << std::endl;

		PresidentialPardonForm p("pres_dio");
		std::cout << p << std::endl;
		std::cout << p.getTarget() << std::endl;
	
		PresidentialPardonForm t(p);
		std::cout << t << std::endl;
		std::cout << t.getTarget() << std::endl;
		p.beSigned(c);
		c.executeForm(p);

		t.beSigned(b);
		b.executeForm(t);
		std::cout << "-------------------------------------" << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception called: " << e.what() << std::endl;
	}
	return(0);
}
