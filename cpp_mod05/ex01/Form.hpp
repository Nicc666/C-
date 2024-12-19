/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nspinell <nspinell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 15:44:32 by nspinell          #+#    #+#             */
/*   Updated: 2024/12/19 17:56:54 by nspinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

class Form
{
	private:
		const std::string name;
		int firmed;
		const int gradesign;
		const int gradeexec;
	public:
		Form();
		//Form(const std::string name, int grade);
		Form(Form const &other);
		Form &operator=(Form const &other);
		~Form();
		int getGradeSign() const;
		int getGradeExec() const;
		std::string getName() const;
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

std::ostream &operator<<(std::ostream &out, Form const &b);
