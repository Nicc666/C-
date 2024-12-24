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
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	Animal a;
	a.makeSound();
	std::cout << "Animal type: " <<a.getType() << std::endl;
	std::cout << "----------------------" << std::endl;
	Dog d;
	d.makeSound();
	std::cout << "Dog type: " <<d.getType() << std::endl;
	std::cout << "----------------------" << std::endl;
	Dog copy(d);
	copy.makeSound();
	std::cout << "Dog copy type: " <<copy.getType() << std::endl;
	std::cout << "----------------------" << std::endl;
	Cat c;
	c.makeSound();
	std::cout << "Cat type: " <<c.getType() << std::endl;
	std::cout << "----------------------" << std::endl;
	Cat cop(c);
	cop.makeSound();
	std::cout << "Cat copy type: " <<cop.getType() << std::endl;
	std::cout << "----------------------" << std::endl;

	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();
	delete meta;
	delete j;
	delete i;
	std::cout << "----------------------" << std::endl;

	const WrongAnimal* wrong = new WrongAnimal();
	const WrongAnimal* iii = new WrongCat();
	const WrongCat *wc = new WrongCat();
	std::cout << iii->getType() << " " << std::endl;
	iii->makeSound();
	wrong->makeSound();
	wc->makeSound();
	delete wrong;
	delete iii;
	delete wc;
	return (0);
}
