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
	std::cout << "----------------------" << std::endl;
	int z = 0;
	Cat *cat = new Cat();
	Dog *dog = new Dog();
	std::cout << "cat: " << cat->getType() << std::endl;
	std::cout << "dog: " << dog->getType() << std::endl;
	cat->makeSound();
	dog->makeSound();
	for (z = 0; z < 100; z++)
		cat->set_idea(z, "idea");
	for (z = 0; z < 100; z++)
		std::cout << z << " " << cat->get_idea(z) << std::endl;
	Cat *cat2 = new Cat(*cat);
	std::cout << "copy cat: " << cat->getType() << std::endl;
	cat->makeSound();
	for (z = 0; z < 100; z++)
		std::cout << "copy cat idea: " << z << " " << cat->get_idea(z) << std::endl;
	delete cat;
	delete dog;
	delete cat2;
	std::cout << "----------------------" << std::endl;
	Animal *array[10];
	for (z = 0; z < 5; z++)
		array[z] = new Dog();
	for (z = 5; z < 10; z++)
		array[z] = new Cat();
	std::cout << "array sound" << std::endl;
	for (z = 0; z < 10; z++)
		array[z]->makeSound();
	for (z = 0; z < 10; z++)
		delete array[z];
	std::cout << "----------------------" << std::endl;
	Dog basic;
	for (z = 0; z < 100; z++)
		basic.set_idea(z, "basic idea");
	{
    	Dog tmp = basic; // Copia il dog "basic" in "tmp"
		tmp.set_idea(0, "temp idea");
		tmp.set_idea(1, "temp idea2");
		std::cout << "temp idea: " << tmp.get_idea(0) << std::endl;
		std::cout << "temp idea: " << tmp.get_idea(1) << std::endl;
	} // Distruzione di "tmp" e verifica che "basic" non sia corrotto
	for (z = 0; z < 100; z++)
		std::cout << z << " " << basic.get_idea(z) << std::endl;
	return (0);
}
