
#include "ASpell.hpp"

ASpell::ASpell()
{
}

ASpell::ASpell(const ASpell &other)
{
    *this = other;
}

ASpell &ASpell::operator=(const ASpell &other)
{
    if (this == &other)
        return (*this);
    name = other.name;
    effects = other.effects;
    return (*this);
}

ASpell::~ASpell()
{
}

const std::string &ASpell::getName(void) const
{
    return(this->name);
}

const std::string &ASpell::getEffects(void) const
{
    return(this->effects);
}
