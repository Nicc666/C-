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
	Data *data_test;

	data.s = "Ciao";
	data.x = 12;
	data.c = 'Q';
	std::cout << "Original Data address: " << &data << std::endl;
	int_add = Serializer::serialize(&data);
	std::cout << "Serialized address: " << int_add << std::endl;
	data_test = Serializer::deserialize(int_add);
	std::cout << "Deserialized address: " << data_test << std::endl;
	std::cout << "Data test s: " << data_test->s << std::endl;
	std::cout << "Data test x: " << data_test->x << std::endl;
	std::cout << "Data test c: " << data_test->c << std::endl;
	return(0);
}
