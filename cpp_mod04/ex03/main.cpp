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

#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"

int main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	delete bob;
	delete me;
	delete src;

	std::cout << "---------------------" << std::endl;
	MateriaSource* ms = new MateriaSource();
	Cure *c = new Cure();
	ms->learnMateria(c);
	Ice *i = new Ice();
	ms->learnMateria(i);
	Ice *i2 = new Ice();
	ms->learnMateria(i2);
	Ice *i3 = new Ice();
	ms->learnMateria(i3);
	Ice *i4 = new Ice();
	ms->learnMateria(i4);
	delete i4;
	delete ms;

	std::cout << "---------------------" << std::endl;
	Cure *test = new Cure();
	Character* p = new Character("pippo");
	p->equip(test);
	p->unequip(0);
	delete test;
	delete p;
	return 0;
}
