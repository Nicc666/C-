/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nspinell <nspinell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 18:44:32 by nspinell          #+#    #+#             */
/*   Updated: 2025/01/12 19:56:54 by nspinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

template <typename T>
void swap(T &x, T &y)
{
	T tmp;
	tmp = x;
	x = y;
	y = tmp;
	return;
}

template <typename T>
const T min(const T &x, const T &y)
{
	if (x < y)
		return x;
	else
		return y;
}

template <typename T>
const T max(const T &x, const T &y)
{
	if (x > y)
		return x;
	else
		return y;
}

#endif
