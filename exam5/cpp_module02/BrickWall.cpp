#include "BrickWall.hpp"
#include "ASpell.hpp"

BrickWall::BrickWall() : ATarget("Inconspicuous Red-brick Wall")
{
}

BrickWall::BrickWall(const BrickWall &other) : ATarget(other)
{
}

BrickWall::~BrickWall()
{
}

ATarget *BrickWall::clone(void) const
{
	return(new BrickWall(*this));
}
