#pragma once

#include <string>
#include <iostream>
#include "ATarget.hpp"

class Dummy : public ATarget
{
    public:
		Dummy();
		Dummy(const Dummy &other);
		Dummy &operator=(const Dummy &other);
		Dummy(const std::string &type);
		virtual ATarget *clone(void) const;
		virtual ~Dummy();
};