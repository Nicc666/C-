
#include <string>
#include <iostream>

class ASpell
{
    private:
        std::string name;
        std::string effects;
    public:
        ASpell();
        ASpell(const ASpell &other);
        ASpell &operator=(const ASpell &other);
        virtual ~ASpell() = 0;
        const std::string &getName(void) const;
        const std::string &getEffects(void) const;
        virtual ASpell *clone(void) = 0;
};
