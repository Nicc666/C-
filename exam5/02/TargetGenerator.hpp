#ifndef TARGETGENERATOR_HPP
#define TARGETGENERATOR_HPP

#include <string>
#include <iostream>
#include <vector>
#include "ATarget.hpp"
#include "BrickWall.hpp"

class TargetGenerator
{
    private:
        std::vector<ATarget *> list;
        TargetGenerator(const TargetGenerator &other);
        TargetGenerator &operator=(const TargetGenerator &other);
    public:
        TargetGenerator();
        virtual ~TargetGenerator();
        void learnTargetType(ATarget *target);
        void forgetTargetType(std::string const &target);
        ATarget* createTarget(std::string const &target);
};

#endif