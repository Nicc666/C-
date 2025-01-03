/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nspinell <nspinell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 15:44:32 by nspinell          #+#    #+#             */
/*   Updated: 2024/12/19 17:56:54 by nspinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

AForm::AForm() : name("default"), firmed(false), gradesign(50), gradeexec(50)
{
}

AForm::AForm(std::string name, int grades, int gradee) : name(name), firmed(false), gradesign(grades), gradeexec(gradee)
{
}

AForm::AForm(AForm const &other) : name(other.name), gradesign(other.gradesign), gradeexec(other.gradeexec)
{
	*this = other;
}

AForm &AForm::operator=(AForm const &other)
{
	this->firmed = other.firmed;
	return (*this);
}

AForm::~AForm()
{
}

std::string AForm::getName() const
{
	return (this->name);
}

int AForm::getGradeSign() const
{
	return (this->gradesign);
}

int AForm::getGradeExec() const
{
	return (this->gradeexec);
}

bool AForm::getFirmed() const
{
	return (this->firmed);
}

bool AForm::beSigned(Bureaucrat &b)
{
	if (this->firmed == true)
	{
		std::cout << "Form already signed" << std::endl;
		return (0);
	}
	if (b.getGrade() <= this->gradesign)
		this->firmed = true;
	else
		throw AForm::GradeTooLowException();
	return (1);
}

void AForm::execute(Bureaucrat const &executor) const
{
	if (this->firmed == false)
		throw AForm::NotSignedException();
	if (executor.getGrade() > this->gradeexec)
		throw AForm::GradeToExecuteException();
	else
	{
		this->execution();
	}
	return ;
}

std::ostream &operator<<(std::ostream &out, AForm const &f)
{
	std::cout << "Form name: " << f.getName() << ", firmed: " << f.getFirmed() << ", grade to sign: " << f.getGradeSign() << ", grade to execute: " << f.getGradeExec();
	return (out);
}
