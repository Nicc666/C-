#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie
{
	public:
		Zombie();
		Zombie(std::string ssname);
		~Zombie();
		void announce(void);
		void nameset(std::string ssname);
	private:
		std::string name;
};

Zombie* zombieHorde( int N, std::string name );

#endif
