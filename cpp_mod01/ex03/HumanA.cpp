#include "HumanA.hpp"

HumanA::HumanA(std::string nam, Weapon &wea) : name(nam), weapon(wea)
{
}

HumanA::~HumanA()
{
}

void HumanA::attack()
{
    std::cout << name << " attacks with their " << weapon.getType() << std::endl;
    return ;
}