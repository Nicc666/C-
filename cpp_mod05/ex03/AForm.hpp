/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nspinell <nspinell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 15:44:32 by nspinell          #+#    #+#             */
/*   Updated: 2024/12/19 17:56:54 by nspinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <ostream>
#include <fstream>
#include <string>
#include <cstdlib>

class Bureaucrat;

class AForm
{
	private:
		const std::string name;
		bool firmed;
		const int gradesign;
		const int gradeexec;
	protected:
		virtual void execution() const = 0;
	public:
		AForm();
		AForm(const std::string name, int gradesign, int gradeexec);
		AForm(AForm const &other);
		AForm &operator=(AForm const &other);
		virtual ~AForm() = 0;
		int getGradeSign() const;
		int getGradeExec() const;
		std::string getName() const;
		bool getFirmed() const;
		bool beSigned(Bureaucrat &b);
		void execute(Bureaucrat const &executor) const;
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("Form: Grade is too high");
				}
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("Form: Grade is too low");
				}
		};
		class GradeToExecuteException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("Form: Grade is not enough to execute");
				}
		};
		class NotSignedException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("Form: not signed");
				}
		};
};

std::ostream &operator<<(std::ostream &out, AForm const &b);

#endif
