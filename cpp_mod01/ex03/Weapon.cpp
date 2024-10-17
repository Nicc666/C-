#include "Weapon.hpp"

Weapon::Weapon(std::string ty)
{
	type = ty;
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