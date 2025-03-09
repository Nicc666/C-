#include "Dummy.hpp"
#include "ASpell.hpp"

Dummy::Dummy() : ATarget("Target Practice Dummy")
{
}

Dummy::Dummy(const Dummy &other) : ATarget(other)
{
    *this = other;
}

Dummy &Dummy::operator=(const Dummy &other)
{
    this->type = other.type;
    return(*this);
}

Dummy::Dummy(const std::string &type) : ATarget(type)
{
}

Dummy::~Dummy()
{
}

ATarget *Dummy::clone(void) const
{
	return(new Dummy(*this));
}
