#include "TargetGenerator.hpp"
#include "Dummy.hpp"

TargetGenerator::TargetGenerator()
{
}

TargetGenerator::~TargetGenerator()
{
	std::vector<ATarget *>::iterator it = t.begin();
	for(;it != t.end(); )
	{
		delete *it;
		it = t.erase(it);
	}
}

void TargetGenerator::learnTargetType(ATarget *target)
{
    if (target != NULL)
		t.push_back(target->clone());
}

void TargetGenerator::forgetTargetType(const std::string &target)
{
	std::vector<ATarget *>::iterator it = t.begin();
	for(;it != t.end(); )
	{
		if ((*it)->getType() == target)
		{
			delete *it;
			it = t.erase(it);
		}
		else
			it++;
	}
}

ATarget *TargetGenerator::createTarget(const std::string &target)
{
	std::vector<ATarget *>::iterator it = t.begin();
	for(;it != t.end(); it++)
	{
		if ((*it)->getType() == target)
		{
			return(*it);
		}
	}
	return(new Dummy(target));
}
