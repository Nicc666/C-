/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nspinell <nspinell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 12:44:32 by nspinell          #+#    #+#             */
/*   Updated: 2025/01/17 12:56:54 by nspinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <algorithm>
#include <vector>
#include <climits>
#include <iostream>

class Span
{
	private:
		std::vector<int> v;
		unsigned int max;
	public:
		Span();
		Span(unsigned int n);
		Span(const Span &other);
		Span &operator=(const Span &other);
		~Span();
		void addNumber(int number);
		int shortestSpan();
		int longestSpan();
		int getvnum(int i);
		unsigned int getmax(void);
		void printvector(void);
		void insertmanynum(std::vector<int> v2);
		class OutlimitsException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("vector maximum numbers reached");
				}
		};
		class spanException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("not possible calculate span");
				}
		};
};

#endif
