#include "Dummy.hpp"
#include "ASpell.hpp"

Dummy::Dummy() : ATarget("Target Practice Dummy")
{
}

Dummy::Dummy(const Dummy &other) : ATarget(other)
{
}

Dummy::~Dummy()
{
}

ATarget *Dummy::clone(void) const
{
	return(new Dummy(*this));
}
