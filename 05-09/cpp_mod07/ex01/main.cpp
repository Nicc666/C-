/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nspinell <nspinell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 18:44:32 by nspinell          #+#    #+#             */
/*   Updated: 2025/01/12 19:56:54 by nspinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "iter.hpp"

class Awesome
{
  public:
    Awesome( void ) : _n( 42 ) { return; }
    int get( void ) const { return this->_n; }
  private:
    int _n;
};

std::ostream & operator<<( std::ostream & o, Awesome const & rhs )
{
  o << rhs.get();
  return o;
}

template< typename T >
void print( const T& x )
{
  std::cout << x << std::endl;
  return;
}

void increment(int &i)
{
	i = i + 10;
	return;
}

void toupperrr(char &c)
{
	c = c - 32;
	return;
}

void readread(const char &c)
{
	std::cout << c << std::endl;
	return;
}

void print_mio(const int &x)
{
	std::cout << x << std::endl;
	return;
}

int main( void )
{
	int array[5] = {1, 2, 3, 4, 5};
	char *s = new char[20];

	for (int j = 0; j < 20; j++)
	{
		s[j] = 'a' + j;
	}
	s[20] = '\0';
	iter(s, 20, toupperrr);
	std::cout << s << std::endl;
	iter(array, 5, increment);
	for (int i = 0; i < 5; i++)
	{
		std::cout << array[i] << std::endl;
	}
	delete[] s;
	std::cout << "--------------------------------------------------" << std::endl;
	const char cc[5] = {'A', 'B', 'C', 'D', 'E'};
	iter(cc, 5, readread);
	std::cout << "--------------------------------------------------" << std::endl;
	const int x[5] = {6, 7, 8, 9, 10};
	iter(x, 5, print_mio);

	std::cout << "Test ex01.cpp--------------------------------" << std::endl;
	std::cout << "--------------------------------------------------" << std::endl;

	int tab[] = { 0, 1, 2, 3, 4 };
	Awesome tab2[5];

	iter( tab, 5, print<const int> );
	iter( tab2, 5, print<Awesome> );
	return 0;
}
