
#ifndef ATARGET_HPP
#define ATARGET_HPP

#include <string>
#include <iostream>

class ASpell;

class ATarget
{
    protected:
        std::string type;
    public:
        //ATarget();
        ATarget(const std::string &t);
        ATarget(const ATarget &other);
        ATarget &operator=(const ATarget &other);
        virtual ~ATarget() = 0;
        const std::string &getType(void) const;
        virtual ATarget *clone(void) const = 0;
        void getHitBySpell(const ASpell &s) const;
};

#endif