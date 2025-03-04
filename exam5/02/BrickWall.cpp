
#include "BrickWall.hpp"

BrickWall::BrickWall() : ATarget("Inconspicuous Red-brick Wall")
{
}

BrickWall::BrickWall(const std::string &t) : ATarget(t)
{
}

BrickWall::BrickWall(const BrickWall &other) : ATarget(other)
{
	*this = other;
}

BrickWall &BrickWall::operator=(const BrickWall &other)
{
	if (this == &other)
		return (*this);
	type = other.type;
	return (*this);
}

BrickWall::~BrickWall()
{
}

ATarget *BrickWall::clone(void) const
{
	return (new BrickWall(*this));
}
