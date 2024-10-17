#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <string>
#include <iostream>
#include "Weapon.hpp"

class HumanB
{
	public:
		HumanB(std::string nam);
		~HumanB();
		void attack();
		void setWeapon(Weapon &wea);
	private:
		std::string name;
		Weapon *weapon;
};

#endif
