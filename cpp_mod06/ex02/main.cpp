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

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int main(void)
{
	Base *b = new Base();
	identify(b);

	Base *test = generate();
	identify(test);
	identify(*test);

	A a;
	identify(a);
	B bb;
	identify(bb);
	C c;
	identify(c);
	
	delete b;
	delete test;
	return(0);
}
