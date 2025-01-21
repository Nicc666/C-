/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.tpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nspinell <nspinell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 12:44:32 by nspinell          #+#    #+#             */
/*   Updated: 2025/01/17 12:56:54 by nspinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

template <typename T>
Span<T>::Span()
{
	std::vector<int> v(0);
}

template <typename T>
Span<T>::Span(unsigned int n)
{
	std::vector<int> v(n);
}

template <typename T>
Span<T>::Span(const Span &other)
{
	std::vector<int> v(other.n);
	*this = other;
}

template <typename T>
Span<T> &Span<T>::operator=(const Span &other)
{
	this->v = other.v;
}

template <typename T>
Span<T>::~Span()
{
}
