/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nspinell <nspinell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 12:44:32 by nspinell          #+#    #+#             */
/*   Updated: 2025/01/29 12:56:54 by nspinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <list>
#include <cstdlib>
#include <climits>

class RPN
{
	private:
		std::list<int> data;
	public:
		RPN(void);
		RPN(const RPN &other);
		RPN &operator=(const RPN &other);
		~RPN(void);
		static bool inputerror(std::string s);
		void printlist(void);
		void rpn(std::string s);
		bool isnumber(std::string s);
		bool operation(char c);
		int add(int x, int y);
		int minus(int x, int y);
		int moltiplication(int x, int y);
		int divide(int x, int y);
		class invalidexpression : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("Exception: Invalid expression");
				}
		};
};
