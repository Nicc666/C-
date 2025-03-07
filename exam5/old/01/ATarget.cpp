
#include "ATarget.hpp"
#include "ASpell.hpp"

ATarget::ATarget()
{
}

ATarget::ATarget(const ATarget &other)
{
    *this = other;
}

ATarget::ATarget(const std::string &t)
{
    this->type = t;
}

ATarget &ATarget::operator=(const ATarget &other)
{
    if (this == &other)
        return (*this);
    type = other.type;
    return (*this);
}

ATarget::~ATarget()
{
}

const std::string &ATarget::getType(void) const
{
    return(this->type);
}

void ATarget::getHitBySpell(const ASpell &s) const
{
    std::cout << this->type << " has been " << s.getEffects() << "!" << std::endl;
}
