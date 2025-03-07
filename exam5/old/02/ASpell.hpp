
#ifndef ASPELL_HPP
#define ASPELL_HPP

#include <string>
#include <iostream>

class ATarget;

class ASpell
{
    protected:
        std::string name;
        std::string effects;
    public:
        //ASpell();
        ASpell(const std::string &n, const std::string &e);
        ASpell(const ASpell &other);
        ASpell &operator=(const ASpell &other);
        virtual ~ASpell() = 0;
        const std::string &getName(void) const;
        const std::string &getEffects(void) const;
        virtual ASpell *clone(void) const = 0;
        void launch(const ATarget &t) const;
};

#endif