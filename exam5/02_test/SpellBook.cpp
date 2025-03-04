
#include "SpellBook.hpp"

SpellBook::SpellBook()
{
}

SpellBook::~SpellBook()
{
	std::vector<ASpell *>::iterator it = list.begin();
	for (;it != list.end(); )
	{
		delete (*it);
		it = list.erase(it);
	}
}

void SpellBook::learnSpell(ASpell *spell)
{
	if (spell == NULL)
		return;
	for (std::vector<ASpell*>::iterator it = list.begin(); it != list.end(); it++)
    {
        if ((*it)->getName() == spell->getName()) 
        {
            return;//already learned
        }
    }
	list.push_back(spell->clone());
}

void SpellBook::forgetSpell(std::string const &spell)
{
	std::vector<ASpell *>::iterator it = list.begin();
	for (;it != list.end(); )
	{
		if ((*it)->getName() == spell)
		{
			delete (*it);
			it = list.erase(it);
		}
		else
			it++;
	}
}

ASpell* SpellBook::createSpell(std::string const &spell)
{
	std::vector<ASpell *>::iterator it = list.begin();
	for (;it != list.end(); it++)
	{
		if ((*it)->getName() == spell)
		{
			return((*it));
		}
	}
	return (NULL);
}
