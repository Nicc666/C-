
#include "Warlock.hpp"

Warlock::Warlock()
{
}

Warlock::Warlock(const Warlock &other)
{
    *this = other;
}

Warlock &Warlock::operator=(const Warlock &other)
{
    if (this == &other)
        return (*this);
    name = other.name;
    title = other.title;
    return (*this);
}

Warlock::Warlock(const std::string &name, const std::string &title)
{
    this->name = name;
    this->title = title;
    std::cout << this->name << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock()
{
    std::cout << this->name << ": My job here is done!" << std::endl;
}

const std::string &Warlock::getName(void) const
{
    return(this->name);
}

const std::string &Warlock::getTitle(void) const
{
    return(this->title);
}

void Warlock::setTitle(const std::string &title)
{
    this->title = title;
}

void Warlock::introduce(void) const
{
    std::cout << this->name << ": I am " << name << " " << title << "!" << std::endl;
}
