
#ifndef POLYMORPH_HPP
#define POLYMORPH_HPP

#include <string>
#include <iostream>
#include "ASpell.hpp"

class Polymorph : public ASpell
{
    public:
        Polymorph();
        Polymorph(const Polymorph &other);
        Polymorph &operator=(const Polymorph &other);
        virtual ~Polymorph();
        virtual ASpell *clone(void) const;
};

#endif