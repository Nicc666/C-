#include "Zombie.hpp"

int	main(void)
{
	Zombie *zzz;

	zzz = newZombie("Panda");
	zzz->announce();
	randomChump("KKK");
	delete zzz;
	return(0);
}
