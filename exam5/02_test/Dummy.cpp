
#include "Dummy.hpp"

Dummy::Dummy() : ATarget("Target Practice Dummy")
{
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

ATarget *Dummy::clone(void)
{
	ATarget *d = new Dummy();
	return (d);
}
