#pragma once

#include <string>
#include <iostream>
#include <vector>
#include "ASpell.hpp"
#include "ATarget.hpp"

class TargetGenerator
{
		private:
			std::vector<ATarget *> t;
			TargetGenerator(const TargetGenerator &other);
			TargetGenerator &operator=(const TargetGenerator &other);
		public:
			TargetGenerator();
			void learnTargetType(ATarget *target);
			void forgetTargetType(std::string const &target);
			ATarget *createTarget(std::string const &target);
			~TargetGenerator();
};