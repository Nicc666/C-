#pragma once

#include <string>
#include <iostream>
#include <vector>
#include "ASpell.hpp"
#include "ATarget.hpp"
#include "SpellBook.hpp"

class Warlock
{
	private:
		std::string name;
		std::string title;
		SpellBook b;
		Warlock();
		Warlock(const Warlock &other);
		Warlock &operator=(const Warlock &other);
	public:
		Warlock(const std::string &name, const std::string &title);
		const std::string getName(void) const;
		const std::string getTitle(void) const;
		void setTitle(const std::string &title);
		void introduce(void) const;
		void learnSpell(ASpell *spell);
		void forgetSpell(std::string spell);
		void launchSpell(std::string spell, const ATarget &t);
		~Warlock();
};