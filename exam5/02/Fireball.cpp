
#include "Fireball.hpp"

Fireball::Fireball()
{
    name = "Fireball";
    effects = "burnt to a crisp";
}

Fireball::Fireball(const Fireball &other) : ASpell(other)
{
    *this = other;
}

Fireball &Fireball::operator=(const Fireball &other)
{
    if (this == &other)
        return (*this);
    name = other.name;
    effects = other.effects;
    return (*this);
}

Fireball::~Fireball()
{
}

Fireball *Fireball::clone(void)
{
    Fireball *f = new Fireball();
    return (f);
}