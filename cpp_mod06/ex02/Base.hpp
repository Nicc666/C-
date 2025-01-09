/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nspinell <nspinell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 15:44:32 by nspinell          #+#    #+#             */
/*   Updated: 2025/01/05 17:56:54 by nspinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
#define BASE_HPP

#include <cstdlib>
#include <iostream>
#include <ctime>

class Base
{
	public:
		virtual ~Base(void);
};

Base *generate(void);
void identify(Base* p);
void identify(Base& p);

#endif