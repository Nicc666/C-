#include "Zombie.hpp"

void	Zombie::announce(void)
{
	std::cout << name << ": " << "BraiiiiiiinnnzzzZ..." << std::endl;
} 

Zombie::Zombie(std::string ssname)
{
	name = ssname;
}

Zombie::Zombie()
{
}

Zombie::~Zombie()
{
	std::cout << name << ": " << "dead" << std::endl;
}

void	Zombie::nameset(std::string ssname)
{
	name = ssname;
}
 