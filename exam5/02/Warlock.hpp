#ifndef WARLOCK_HPP
#define WARLOCK_HPP

#include <string>
#include <iostream>
#include <vector>
#include "ASpell.hpp"
#include "ATarget.hpp"

class Warlock
{
    private:
        std::string name;
        std::string title;
        std::vector<ASpell *> spell;
        Warlock();
        Warlock(const Warlock &other);
        Warlock &operator=(const Warlock &other);
    public:
        Warlock(const std::string &name, const std::string &title);
        ~Warlock();
        const std::string &getName(void) const;
        const std::string &getTitle(void) const;
        void setTitle(const std::string &title);
        void introduce(void) const;
        void learnSpell(ASpell *s);
        void forgetSpell(std::string spell_name);
        void launchSpell(std::string spell_name, const ATarget &t);
};

#endif