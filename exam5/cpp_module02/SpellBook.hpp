#pragma once

#include <string>
#include <iostream>
#include <vector>
#include "ASpell.hpp"
#include "ATarget.hpp"

class SpellBook
{
    private:
		std::vector<ASpell *> s;
        SpellBook(const SpellBook &other);
        SpellBook &operator=(const SpellBook &other);
    public:
		SpellBook();
		void learnSpell(ASpell *spell);
		void forgetSpell(const std::string &spell);
		ASpell *createSpell(const std::string &spell);
        ~SpellBook();
};