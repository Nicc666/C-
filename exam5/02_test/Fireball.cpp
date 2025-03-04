
#include "Fireball.hpp"

Fireball::Fireball() : ASpell("Fireball", "burnt to a crisp")
{
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

ASpell *Fireball::clone(void) const
{
	ASpell *f = new Fireball();
	return (f);
}