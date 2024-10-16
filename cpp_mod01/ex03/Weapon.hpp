#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>
#include <iostream>

class Weapon
{
	public:
		Weapon();
		~Weapon();
		const std::string &getType();
		void setType(std::string newtype);
	private:
		std::string type;
};

#endif
