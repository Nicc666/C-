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

template <typename T>
typename T::iterator easyfind(T &src, const int &i)
{
	typename T::iterator ret;
	ret = std::find(src.begin(), src.end(), i);
	if (ret != src.end())
		return(ret);
	else
		throw std::exception();
}

#endif
