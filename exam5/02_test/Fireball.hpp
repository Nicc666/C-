
#ifndef FIREBALL_HPP
#define FIREBALL_HPP

#include <string>
#include <iostream>
#include "ASpell.hpp"

class Fireball : public ASpell
{
    public:
        Fireball();
        Fireball(const Fireball &other);
        Fireball &operator=(const Fireball &other);
        virtual ~Fireball();
        virtual ASpell *clone(void);
};

#endif