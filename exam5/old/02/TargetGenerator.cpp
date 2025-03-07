
#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator()
{
}

TargetGenerator::~TargetGenerator()
{
	std::vector<ATarget *>::iterator it = list.begin();
	for(;it !=list.end();)
	{
		delete *it;
		it = list.erase(it);
	}
}

void TargetGenerator::learnTargetType(ATarget *target)
{
	if (target == NULL)
		return;
	for (std::vector<ATarget*>::iterator it = list.begin(); it != list.end(); it++)
    {
        if ((*it)->getType() == target->getType()) 
        {
            return;//already learned
        }
    }
	list.push_back(target->clone());
}

void TargetGenerator::forgetTargetType(std::string const &target)
{
	std::vector<ATarget *>::iterator it = list.begin();
	for(;it !=list.end();)
	{
		if ((*it)->getType() == target)
		{
			delete *it;
			it = list.erase(it);
		}
		else
			it++;
	}
}

ATarget* TargetGenerator::createTarget(std::string const &target)
{
	std::vector<ATarget *>::iterator it = list.begin();
	for(;it !=list.end(); it++)
	{
		if ((*it)->getType() == target)
		{
			return ((*it));
		}
	}
	return new BrickWall(target);
}
