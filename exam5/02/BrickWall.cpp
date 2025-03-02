
#include "BrickWall.hpp"

BrickWall::BrickWall()
{
    type = "Inconspicuous Red-brick Wall";
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

BrickWall *BrickWall::clone(void)
{
    BrickWall *d = new BrickWall();
    return (d);
}
