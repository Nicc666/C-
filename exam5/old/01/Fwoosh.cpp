
#include "Fwoosh.hpp"

Fwoosh::Fwoosh()
{
    name = "Fwoosh";
    effects = "fwooshed";
}

Fwoosh::Fwoosh(const Fwoosh &other) : ASpell(other)
{
    *this = other;
}

Fwoosh &Fwoosh::operator=(const Fwoosh &other)
{
    if (this == &other)
        return (*this);
    name = other.name;
    effects = other.effects;
    return (*this);
}

Fwoosh::~Fwoosh()
{
}

Fwoosh *Fwoosh::clone(void)
{
    Fwoosh *f = new Fwoosh();
    return (f);
}