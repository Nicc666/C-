
#include "ASpell.hpp"
#include "ATarget.hpp"

/*
ASpell::ASpell()
{
}*/

ASpell::ASpell(const ASpell &other)
{
	*this = other;
}

ASpell::ASpell(const std::string &n, const std::string &e)
{
	this->name = n;
	this->effects = e;
}

ASpell &ASpell::operator=(const ASpell &other)
{
	if (this == &other)
		return (*this);
	name = other.name;
	effects = other.effects;
	return (*this);
}

ASpell::~ASpell()
{
}

const std::string &ASpell::getName(void) const
{
	return(this->name);
}

const std::string &ASpell::getEffects(void) const
{
	return(this->effects);
}

void ASpell::launch(const ATarget &t) const
{
	t.getHitBySpell(*this);
}
