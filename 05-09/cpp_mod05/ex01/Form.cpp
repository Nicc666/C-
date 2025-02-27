/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nspinell <nspinell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 15:44:32 by nspinell          #+#    #+#             */
/*   Updated: 2024/12/19 17:56:54 by nspinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

Form::Form() : name("default"), firmed(false), gradesign(50), gradeexec(50)
{
}

Form::Form(std::string name, int grades, int gradee) : name(name), firmed(false), gradesign(grades), gradeexec(gradee)
{
}

Form::Form(Form const &other) : name(other.name), gradesign(other.gradesign), gradeexec(other.gradeexec)
{
	*this = other;
}

Form &Form::operator=(Form const &other)
{
	this->firmed = other.firmed;
	return (*this);
}

Form::~Form()
{
}

std::string Form::getName() const
{
	return (this->name);
}

int Form::getGradeSign() const
{
	return (this->gradesign);
}

int Form::getGradeExec() const
{
	return (this->gradeexec);
}

bool Form::getFirmed() const
{
	return (this->firmed);
}

bool Form::beSigned(Bureaucrat &b)
{
	if (this->firmed == true)
	{
		std::cout << "Form already signed" << std::endl;
		return (0);
	}
	if (b.getGrade() <= this->gradesign)
		this->firmed = true;
	else
		throw Form::GradeTooLowException();
	return (1);
}

std::ostream &operator<<(std::ostream &out, Form const &f)
{
	std::cout << "Form name: " << f.getName() << ", firmed: " << f.getFirmed() << ", grade to sign: " << f.getGradeSign() << ", grade to execute: " << f.getGradeExec();
	return (out);
}
