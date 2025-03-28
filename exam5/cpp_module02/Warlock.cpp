#include "Warlock.hpp"

Warlock::Warlock() : name(""), title("")
{
    std::cout << name << ": This looks like another boring day." << std::endl;
}

Warlock::Warlock(const Warlock &other)
{
    *this = other;
}

Warlock &Warlock::operator=(const Warlock &other)
{
    this->name = other.name;
    this->title = other.title;
    return(*this);
}

Warlock::Warlock(const std::string &name, const std::string &title) : name(name), title(title)
{
    std::cout << name << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock()
{
	std::cout << name << ": My job here is done!" << std::endl;
}

const std::string Warlock::getName(void) const
{
    return(this->name);
}

const std::string Warlock::getTitle(void) const
{
    return(this->title);
}

void Warlock::setTitle(const std::string &title)
{
    this->title = title;
}

void Warlock::introduce(void) const
{
    std::cout << name << ": I am " << name << ", " << title << "!" << std::endl;
}

void Warlock::learnSpell(ASpell *spell)
{
    b.learnSpell(spell);
}

void Warlock::forgetSpell(std::string spell)
{
	b.forgetSpell(spell);
}

void Warlock::launchSpell(std::string spell, const ATarget &t)
{
	ASpell *a = b.createSpell(spell);
	if (a != NULL)
		a->launch(t);
}
