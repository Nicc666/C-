#include "Fireball.hpp"
#include "ATarget.hpp"

Fireball::Fireball() : ASpell("Fireball", "burnt to a crisp")
{
}

Fireball::Fireball(const Fireball &other) : ASpell(other)
{
}

Fireball::~Fireball()
{
}

ASpell *Fireball::clone(void) const
{
	return(new Fireball(*this));
}
