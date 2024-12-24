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

#include <iostream>
#include <string>

class Bureaucrat;

class AForm
{
	private:
		const std::string name;
		bool firmed;
		const int gradesign;
		const int gradeexec;
	public:
		AForm();
		AForm(const std::string name, int gradesign, int gradeexec);
		AForm(AForm const &other);
		AForm &operator=(AForm const &other);
		~AForm();
		int getGradeSign() const;
		int getGradeExec() const;
		std::string getName() const;
		bool getFirmed() const;
		bool beSigned(Bureaucrat &b);
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
};

std::ostream &operator<<(std::ostream &out, AForm const &b);
