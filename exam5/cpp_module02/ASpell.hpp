#pragma once

#include <string>
#include <iostream>

class ATarget;

class ASpell
{
	protected:
		std::string name;
		std::string effects;
    public:
		ASpell();
        ASpell(const ASpell &other);
        ASpell &operator=(const ASpell &other);
		ASpell(const std::string &name, const std::string &effects);
        const std::string getName(void) const;
        const std::string getEffects(void) const;
        virtual ASpell *clone(void) const = 0;
		void launch(const ATarget &target) const;
        virtual ~ASpell();
};