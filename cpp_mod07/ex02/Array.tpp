/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nspinell <nspinell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 18:44:32 by nspinell          #+#    #+#             */
/*   Updated: 2025/01/12 19:56:54 by nspinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template <typename T>
Array<T>::Array()
{
	array = NULL;
}

template <typename T>
Array<T>::Array(unsigned int i)
{
	array = new T[i];
}

template <typename T>
Array<T>::Array(const Array &other)
{
	*this = other;
}

template <typename T>
Array<T> Array<T>::operator&=(const Array &other)
{
	int n = static_cast<int>(other.size());
	this->array = new T[n];
	for(int i=0; i < n; i++)
	{
		this->array[i] = other[i];
	}
	return(*this);
}

template <typename T>
Array<T>::~Array()
{
	delete[] array;
}

template <typename T>
size_t Array<T>::size(void) const
{
	int i = 0;
	while (this->array[i] != NULL)
	{
		i++;
	}
	return(static_cast<size_t>(i));
}
