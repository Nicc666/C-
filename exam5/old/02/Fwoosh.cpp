
#include "Fwoosh.hpp"

Fwoosh::Fwoosh() : ASpell("Fwoosh", "fwooshed")
{
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

ASpell *Fwoosh::clone(void) const
{
	return (new Fwoosh(*this));
}