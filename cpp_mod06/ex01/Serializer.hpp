/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nspinell <nspinell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 15:44:32 by nspinell          #+#    #+#             */
/*   Updated: 2025/01/05 17:56:54 by nspinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <string>
#include <iostream>
#include <stdint.h>

typedef struct sData
{
	std::string s;
	int x;
	char *c;
}	Data;

class Serializer
{
	private:
		Serializer(void);
		Serializer(const Serializer &other);
		Serializer &operator=(const Serializer &other);
	public:
		~Serializer(void);
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};

#endif