#include "ASpell.hpp"
#include "ATarget.hpp"

ASpell::ASpell() : name("nospell"), effects("no")
{
}

ASpell::ASpell(const ASpell &other)
{
    *this = other;
}

ASpell &ASpell::operator=(const ASpell &other)
{
	if (this == &other)
		return (*this);
	this->name = other.name;
    this->effects = other.effects;
    return(*this);
}

ASpell::ASpell(const std::string &name, const std::string &effects) : name(name), effects(effects)
{
}

ASpell::~ASpell()
{
}

const std::string ASpell::getName(void) const
{
    return(this->name);
}

const std::string ASpell::getEffects(void) const
{
    return(this->effects);
}

void ASpell::launch(const ATarget &target) const
{
	target.getHitBySpell(*this);
}
