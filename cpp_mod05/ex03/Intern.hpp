/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nspinell <nspinell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 15:44:32 by nspinell          #+#    #+#             */
/*   Updated: 2024/12/19 17:56:54 by nspinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
	private:
		std::string possibleform[3];
	public:
		Intern();
		Intern(Intern const &other);
		Intern &operator=(Intern const &other);
		~Intern();
		std::string getForm(int i) const;
		AForm *makeForm(std::string const &form, std::string const &target);
		AForm *ShrubberyForm(std::string const &target);
		AForm *RobotomyForm(std::string const &target);
		AForm *PresidentialForm(std::string const &target);
};

#endif
