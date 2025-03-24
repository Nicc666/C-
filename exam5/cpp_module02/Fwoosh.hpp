#pragma once

#include <string>
#include <iostream>
#include "ASpell.hpp"

class Fwoosh : public ASpell
{
    public:
		Fwoosh();
		Fwoosh(const Fwoosh &other);
        virtual ASpell *clone(void) const;
        virtual ~Fwoosh();
};