/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nspinell <nspinell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 15:44:32 by nspinell          #+#    #+#             */
/*   Updated: 2024/12/19 17:56:54 by nspinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyForm", 145, 137), target("default")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyForm", 145, 137), target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &other) : AForm("ShrubberyForm", 145, 137)
{
	*this = other;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &other)
{
	this->target = other.target;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

std::string ShrubberyCreationForm::getTarget() const
{
	return (this->target);
}

void ShrubberyCreationForm::execution() const
{
	std::ofstream file;
	std::string filename;
	filename = this->target + "_shrubbery";
	file.open(filename.c_str(), std::ios_base::out);
	if (file.is_open() == false)
	{
		std::cout << "Error: Opening file" << std::endl;
		return ;
	}
	file << "    ------    " << std::endl;
	file << "  /        \\ " << std::endl;
	file << " |          | " << std::endl;
	file << " |          | " << std::endl;
	file << " \\          / " << std::endl;
	file << "  \\        / " << std::endl;
	file << "    |    | " << std::endl;
	file << "    |    | " << std::endl;
	file << "    |    | " << std::endl;
	file << "   /      \\ " << std::endl;
	file.close();
	return ;
}
