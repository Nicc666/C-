#pragma once

#include <string>
#include <iostream>
#include "ASpell.hpp"

class Fireball : public ASpell
{
    public:
		Fireball();
		Fireball(const Fireball &other);
        virtual ASpell *clone(void) const;
        virtual ~Fireball();
};