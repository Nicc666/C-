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
#include "AForm.hpp"

int main(void)
{
	try
	{
		Bureaucrat b("bur", 139);
		Bureaucrat c("cur", 2);
		Bureaucrat d("dur", 150);
		std::cout << b << std::endl;
		b.decrement();
		AForm f("contract", 140, 140);
		AForm g("newcontr", 1, 1);
		std::cout << f << std::endl;
		std::cout << f.getName() << " " << f.getFirmed() << " " << f.getGradeSign() << " " << f.getGradeExec() << std::endl;
		b.signForm(f);
		b.signForm(f);
		c.signForm(f);
		d.signForm(f);
		d.signForm(g);
		std::cout << g << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception called: " << e.what() << std::endl;
	}
	return(0);
}
