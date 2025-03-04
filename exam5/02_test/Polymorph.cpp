
#include "Polymorph.hpp"

Polymorph::Polymorph() : ASpell("Polymorph", "turned into critter")
{
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

ASpell *Polymorph::clone(void) const
{
	ASpell *f = new Polymorph();
	return (f);
}