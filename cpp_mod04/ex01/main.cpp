/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nspinell <nspinell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 15:44:32 by nspinell          #+#    #+#             */
/*   Updated: 2024/12/07 17:56:54 by nspinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	Animal a;
	Dog d;
	Dog copy(d);
	Cat c;
	Cat cop(c);

	a.makeSound();
	std::cout << "Animal type: " <<a.getType() << std::endl;
	d.makeSound();
	std::cout << "Dog type: " <<d.getType() << std::endl;
	copy.makeSound();
	std::cout << "Dog copy type: " <<copy.getType() << std::endl;
	c.makeSound();
	std::cout << "Cat type: " <<c.getType() << std::endl;
	cop.makeSound();
	return (0);
}
