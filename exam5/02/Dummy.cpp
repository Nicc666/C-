
#include "Dummy.hpp"

Dummy::Dummy()
{
    type = "Target Practice Dummy";
}

Dummy::Dummy(const Dummy &other) : ATarget(other)
{
    *this = other;
}

Dummy &Dummy::operator=(const Dummy &other)
{
    if (this == &other)
        return (*this);
    type = other.type;
    return (*this);
}

Dummy::~Dummy()
{
}

Dummy *Dummy::clone(void)
{
    Dummy *d = new Dummy();
    return (d);
}
