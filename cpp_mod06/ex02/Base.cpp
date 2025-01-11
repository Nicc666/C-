/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nspinell <nspinell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 15:44:32 by nspinell          #+#    #+#             */
/*   Updated: 2025/01/05 17:56:54 by nspinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base(void)
{
}

Base * generate(void)
{
	Base *ret;
	std::srand(std::time(0));
	if ((std::rand() % 3) == 0)
		ret = new A();
	else if ((std::rand() % 3) == 1)
		ret = new B();
	else
		ret = new C();
	return (ret);
}

void identify(Base* p)
{
	if (dynamic_cast <A*> (p) != NULL)
		std::cout << "type is A" << std::endl;
	else if (dynamic_cast <B*> (p) != NULL)
		std::cout << "type is B" << std::endl;
	else if (dynamic_cast <C*> (p) != NULL)
		std::cout << "type is C" << std::endl;
	else
		std::cout << "type is unknown" << std::endl;
	return;
}

void identify(Base& p)
{
	try
	{
		dynamic_cast<A&>(p);
		std::cout << "type is A" << std::endl;
		return;
	}
	catch (std::exception& e)
	{
	}
	try
	{
		dynamic_cast<B&>(p);
		std::cout << "type is B" << std::endl;
		return;
	}
	catch (std::exception& e)
	{
	}
	try
	{
		dynamic_cast<C&>(p);
		std::cout << "type is C" << std::endl;
		return;
	}
	catch (std::exception& e)
	{
	}
	std::cout << "type is unknown" << std::endl;
}
