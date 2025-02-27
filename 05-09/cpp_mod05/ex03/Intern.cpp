/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nspinell <nspinell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 15:44:32 by nspinell          #+#    #+#             */
/*   Updated: 2024/12/19 17:56:54 by nspinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
	possibleform[0] = "shrubbery request";
	possibleform[1] = "robotomy request";
	possibleform[2] = "presidential request";
}

Intern::Intern(Intern const &other) : possibleform(other.possibleform)
{
	*this = other;
}

Intern &Intern::operator=(Intern const &other)
{
	for(int i = 0; i < 3; i++)
	{
		this->possibleform[i] = other.possibleform[i];
	}
	return (*this);
}

Intern::~Intern()
{
}

std::string Intern::getForm(int i) const
{
	return (possibleform[i]);
}

AForm *Intern::ShrubberyForm(std::string const &target)
{
	ShrubberyCreationForm *newform = NULL;
	newform = new ShrubberyCreationForm(target);
	std::cout << "Intern creates " << newform->getName() << std::endl;
	return (newform);
}

AForm *Intern::RobotomyForm(std::string const &target)
{
	RobotomyRequestForm *newform = NULL;
	newform = new RobotomyRequestForm(target);
	std::cout << "Intern creates " << newform->getName() << std::endl;
	return (newform);
}

AForm *Intern::PresidentialForm(std::string const &target)
{
	PresidentialPardonForm *newform = NULL;
	newform = new PresidentialPardonForm(target);
	std::cout << "Intern creates " << newform->getName() << std::endl;
	return (newform);
}

AForm *Intern::makeForm(std::string const &form, std::string const &target)
{
	AForm *newform = NULL;

	AForm *(Intern::*internPointer[3])(std::string const &target);
	internPointer[0] = &Intern::ShrubberyForm;
	internPointer[1] = &Intern::RobotomyForm;
	internPointer[2] = &Intern::PresidentialForm;
	for (int i = 0; i < 3; i++)
	{
		if (form == this->possibleform[i])
		{
			newform = (this->*internPointer[i])(target);
		}
	}
	return (newform);
}
