/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eayfind.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nspinell <nspinell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 12:44:32 by nspinell          #+#    #+#             */
/*   Updated: 2025/01/17 12:56:54 by nspinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <iterator>
#include <exception>

template <typename T>
int *easyfind(T &src, const int &i)
{
	typename T::iterator it_b = src.begin();
	typename T::iterator it_e = src.end();
	typename T::iterator ret;
	ret = std::find(it_b, it_e, i);
	if (ret != it_e)
		return(&(*ret));
	else
		throw std::exception();
}

#endif
