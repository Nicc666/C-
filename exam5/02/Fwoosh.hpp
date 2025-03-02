
#ifndef FWOOSH_HPP
#define FWOOSH_HPP

#include <string>
#include <iostream>
#include "ASpell.hpp"

class Fwoosh : public ASpell
{
    public:
        Fwoosh();
        Fwoosh(const Fwoosh &other);
        Fwoosh &operator=(const Fwoosh &other);
        virtual ~Fwoosh();
        virtual Fwoosh *clone(void);
};

#endif