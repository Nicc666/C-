#pragma once

#include <string>
#include <iostream>
#include "ATarget.hpp"

class BrickWall : public ATarget
{
    public:
		BrickWall();
		BrickWall(const BrickWall &other);
		virtual ATarget *clone(void) const;
		virtual ~BrickWall();
};