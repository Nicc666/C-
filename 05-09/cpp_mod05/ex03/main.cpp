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
#include "Intern.hpp"
#include <ctime>

int main(void)
{
	std::srand(std::time(0));
	try
	{
		Intern i;
		Intern j(i);

		std::cout << "POSSIBILITIES FORM: " << std::endl;
		std::cout << i.getForm(0) << " " << i.getForm(1) << " " << i.getForm(2) << std::endl;
		std::cout << j.getForm(0) << " " << j.getForm(1) << " " << j.getForm(2) << std::endl;

		AForm *f = i.makeForm("shrubbery request", "home");
		AForm *g = i.makeForm("robotomy request", "ciccio");
		AForm *k = i.makeForm("presidential request", "py");
		AForm *e = i.makeForm("error", "eee");
		std::cout << *f << std::endl;
		std::cout << *g << std::endl;
		std::cout << *k << std::endl;
		std::cout << e << std::endl;
		delete f;
		delete g;
		delete k;
		std::cout << "-------------------------------------" << std::endl;
		Intern someRandomIntern;
		AForm* rrf;
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		delete rrf;
		std::cout << "-------------------------------------" << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception called: " << e.what() << std::endl;
	}
	return(0);
}
