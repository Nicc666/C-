
#ifndef DUMMY_HPP
#define DUMMY_HPP

#include <string>
#include <iostream>
#include "ATarget.hpp"

class Dummy : public ATarget
{
    public:
        Dummy();
        Dummy(const Dummy &other);
        Dummy &operator=(const Dummy &other);
        virtual ~Dummy();
        virtual ATarget *clone(void) const;
};

#endif