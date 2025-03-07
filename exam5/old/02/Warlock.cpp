
#include "Warlock.hpp"

Warlock::Warlock(const std::string &name, const std::string &title)
{
	this->name = name;
	this->title = title;
	std::cout << this->name << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock()
{
	std::cout << this->name << ": My job here is done!" << std::endl;
}

const std::string &Warlock::getName(void) const
{
	return(this->name);
}

const std::string &Warlock::getTitle(void) const
{
	return(this->title);
}

void Warlock::setTitle(const std::string &title)
{
	this->title = title;
}

void Warlock::introduce(void) const
{
	std::cout << this->name << ": I am " << name << ", " << title << "!" << std::endl;
}

void Warlock::learnSpell(ASpell *s)
{
	this->book.learnSpell(s);
}

void Warlock::forgetSpell(std::string spell_name)
{
	this->book.forgetSpell(spell_name);
}

void Warlock::launchSpell(std::string spell_name, const ATarget &t)
{
	ASpell *spell = this->book.createSpell(spell_name);
	if (spell != NULL)
	{
		spell->launch(t);
		return;
	}
}
