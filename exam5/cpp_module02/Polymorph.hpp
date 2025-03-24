#pragma once

#include <string>
#include <iostream>
#include "ASpell.hpp"

class Polymorph : public ASpell
{
    public:
		Polymorph();
		Polymorph(const Polymorph &other);
        virtual ASpell *clone(void) const;
        virtual ~Polymorph();
};