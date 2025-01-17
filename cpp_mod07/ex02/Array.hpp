/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nspinell <nspinell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 18:44:32 by nspinell          #+#    #+#             */
/*   Updated: 2025/01/12 19:56:54 by nspinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstddef>

template <typename T>
class Array
{
	private:
		T *array;
		size_t dim;
	public:
		Array();
		Array(unsigned int n);
		Array(const Array &other);
		Array &operator=(const Array &other);
		T &operator[](const int &i);
		~Array();
		size_t size(void) const;
		class OutlimitsException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("number out of array");
				}
		};
};

#include "Array.tpp"

#endif
