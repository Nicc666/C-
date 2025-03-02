
#ifndef BRICKWALL_HPP
#define BRICKWALL_HPP

#include <string>
#include <iostream>
#include "ATarget.hpp"

class BrickWall : public ATarget
{
    public:
        BrickWall();
        BrickWall(const BrickWall &other);
        BrickWall &operator=(const BrickWall &other);
        virtual ~BrickWall();
        virtual BrickWall *clone(void);
};

#endif