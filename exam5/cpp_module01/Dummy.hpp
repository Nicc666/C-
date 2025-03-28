#pragma once

#include <string>
#include <iostream>
#include "ATarget.hpp"

class Dummy : public ATarget
{
    public:
		Dummy();
		Dummy(const Dummy &other);
		virtual ATarget *clone(void) const;
		virtual ~Dummy();
};