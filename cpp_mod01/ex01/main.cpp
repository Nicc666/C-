#include "Zombie.hpp"

int	main(void)
{
	Zombie *z;
	int		i;
	int		N;

	i = 0;
	N = 5;
	z = zombieHorde(N, "KING");
	while (i < N)
	{
		z[i].announce();
		i++;
	}
	delete[] z;
	return(0);
}
