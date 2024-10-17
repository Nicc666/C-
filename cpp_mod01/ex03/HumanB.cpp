#include "HumanB.hpp"

HumanB::HumanB(std::string nam): name(nam), weapon(NULL) 
{
}

HumanB::~HumanB()
{
}

void HumanB::attack()
{
    if (weapon == NULL)
        return ;
    std::cout << name << " attacks with their " << weapon->getType() << std::endl;
    return ;
}

void HumanB::setWeapon(Weapon &wea)
{
    weapon = &wea;
    return ;
}