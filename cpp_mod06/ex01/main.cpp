/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nspinell <nspinell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 15:44:32 by nspinell          #+#    #+#             */
/*   Updated: 2025/01/05 17:56:54 by nspinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main(void)
{
	Data data;
	uintptr_t int_add;
	char c = 'Q';

	data.s = "Ciao";
	data.x = 12;
	data.c = &c;
	int_add = Serializer::serialize(&data);
	std::cout << "Data address: " << &data << std::endl;
	std::cout << "Serialized address: " << int_add << std::endl;
	std::cout << "Deserialized address: " << Serializer::deserialize(int_add) << std::endl;
	return(0);
}
