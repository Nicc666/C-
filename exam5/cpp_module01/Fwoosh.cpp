#include "Fwoosh.hpp"
#include "ATarget.hpp"

Fwoosh::Fwoosh() : ASpell("Fwoosh", "fwooshed")
{
}

Fwoosh::Fwoosh(const Fwoosh &other) : ASpell(other)
{
    *this = other;
}

Fwoosh &Fwoosh::operator=(const Fwoosh &other)
{
    this->name = other.name;
    this->effects = other.effects;
    return(*this);
}

Fwoosh::Fwoosh(const std::string &name, const std::string &effects) : ASpell(name, effects)
{
}

Fwoosh::~Fwoosh()
{
}

ASpell *Fwoosh::clone(void) const
{
	return(new Fwoosh(*this));
}
