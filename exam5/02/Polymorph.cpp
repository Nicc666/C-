
#include "Polymorph.hpp"

Polymorph::Polymorph()
{
    name = "Polymorph";
    effects = "turned into critter";
}

Polymorph::Polymorph(const Polymorph &other) : ASpell(other)
{
    *this = other;
}

Polymorph &Polymorph::operator=(const Polymorph &other)
{
    if (this == &other)
        return (*this);
    name = other.name;
    effects = other.effects;
    return (*this);
}

Polymorph::~Polymorph()
{
}

Polymorph *Polymorph::clone(void)
{
    Polymorph *f = new Polymorph();
    return (f);
}