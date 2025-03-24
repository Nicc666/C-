#include "Polymorph.hpp"
#include "ATarget.hpp"

Polymorph::Polymorph() : ASpell("Polymorph", "turned into a critter")
{
}

Polymorph::Polymorph(const Polymorph &other) : ASpell(other)
{
}

Polymorph::~Polymorph()
{
}

ASpell *Polymorph::clone(void) const
{
	return(new Polymorph(*this));
}
