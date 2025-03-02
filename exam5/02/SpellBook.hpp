
#ifndef SPELLBOOK_HPP
#define SPELLBOOK_HPP

#include <string>
#include <iostream>
#include <vector>
#include "ASpell.hpp"

class SpellBook
{
    protected:
        std::vector<ASpell*> list;
        SpellBook(const SpellBook &other);
        SpellBook &operator=(const SpellBook &other);
    public:
        SpellBook();
        virtual ~SpellBook();
        void learnSpell(ASpell *spell);
        void forgetSpell(std::string const &spell);
        ASpell* createSpell(std::string const &spell);
};

#endif