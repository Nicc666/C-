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
	dim = 0;
	array = NULL;
}

template <typename T>
Array<T>::Array(unsigned int i)
{
	dim = static_cast<size_t>(i);
	if (i == 0)
		array = NULL;
	else
		array = new T[i];
}

template <typename T>
Array<T>::Array(const Array &other)
{
	this->dim = 0;
	this->array = NULL;
	*this = other;
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &other)
{
	if (this == &other)
		return(*this);
	this->dim = other.size();
	if (other.size() == 0)
	{
		return(*this);
	}
	delete[] this->array;
	int n = static_cast<int>(other.size());
	this->array = new T[n];
	for(int i=0; i < n; i++)
	{
		this->array[i] = other.array[i];
	}
	return(*this);
}

template <typename T>
T &Array<T>::operator[](const int &i)
{
	if (i < 0 || i >= static_cast<int>(this->dim))
	{
		throw Array<T>::OutlimitsException();
	}
	else
		return(this->array[i]);
}

template <typename T>
const T &Array<T>::operator[](const int &i) const
{
	if (i < 0 || i >= static_cast<int>(this->dim))
	{
		throw Array<T>::OutlimitsException();
	}
	else
		return(this->array[i]);
}

template <typename T>
Array<T>::~Array()
{
	delete[] array;
}

template <typename T>
size_t Array<T>::size(void) const
{
	return(dim);
}
