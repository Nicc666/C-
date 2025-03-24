#include "Fwoosh.hpp"
#include "ATarget.hpp"

Fwoosh::Fwoosh() : ASpell("Fwoosh", "fwooshed")
{
}

Fwoosh::Fwoosh(const Fwoosh &other) : ASpell(other)
{
}

Fwoosh::~Fwoosh()
{
}

ASpell *Fwoosh::clone(void) const
{
	return(new Fwoosh(*this));
}
