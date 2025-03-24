#include "SpellBook.hpp"

SpellBook::SpellBook()
{
}

SpellBook::~SpellBook()
{
	std::vector<ASpell *>::iterator it = s.begin();
	for(;it != s.end();)
	{
		delete *it;
		it = s.erase(it);
	}
}

void SpellBook::learnSpell(ASpell *spell)
{
    if (spell != NULL)
		s.push_back(spell->clone());
}

void SpellBook::forgetSpell(const std::string &spell)
{
	std::vector<ASpell *>::iterator it = s.begin();
	for(;it != s.end(); )
	{
		if ((*it)->getName() == spell)
		{
			delete *it;
			it = s.erase(it);
		}
		else
			it++;
	}
}

ASpell *SpellBook::createSpell(const std::string &spell)
{
	std::vector<ASpell *>::iterator it = s.begin();
	for(;it != s.end(); it++)
	{
		if ((*it)->getName() == spell)
		{
			return(*it);
		}
	}
	return(NULL);
}
