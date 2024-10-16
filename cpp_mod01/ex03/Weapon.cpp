#include "Weapon.hpp"

Weapon::Weapon()
{
}

Weapon::~Weapon()
{
}

const std::string &Weapon::getType()
{
	return(type);
}

void Weapon::setType(std::string newtype)
{
	type = newtype;
	return ;
}