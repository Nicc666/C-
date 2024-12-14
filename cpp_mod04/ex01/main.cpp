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
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j;//should not create a leak
	delete i;

	int z = 0;
	Animal *array[10];
	for (z = 0; z < 5; z++)
		array[z] = new Dog();
	for (z = 5; z < 10; z++)
		array[z] = new Cat();
	Cat *cat = new Cat();
	Dog *dog = new Dog();
	std::cout << "cat: " << cat->getType() << std::endl;
	std::cout << "dog: " << dog->getType() << std::endl;
	cat->makeSound();
	dog->makeSound();
	std::cout << "array sound" << std::endl;
	for (z = 0; z < 10; z++)
		array[z]->makeSound();
	std::cout << "----------------------" << std::endl;


	for (z = 0; z < 100; z++)
		cat->set_idea(z, "idea");
	for (z = 0; z < 100; z++)
		std::cout << cat->get_idea(z) << std::endl;

	std::cout << "----------------------" << std::endl;
	delete cat;
	delete dog;
	for (z = 0; z < 10; z++)
		delete array[z];
	return (0);
}
