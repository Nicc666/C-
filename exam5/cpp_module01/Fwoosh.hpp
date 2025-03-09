#pragma once

#include <string>
#include <iostream>
#include "ASpell.hpp"

class Fwoosh : public ASpell
{
    public:
		Fwoosh();
		Fwoosh(const Fwoosh &other);
		Fwoosh &operator=(const Fwoosh &other);
		Fwoosh(const std::string &name, const std::string &effects);
        virtual ASpell *clone(void) const;
        virtual ~Fwoosh();
};