#pragma once

#include <string>
#include <iostream>

class Warlock
{
    private:
        std::string name;
        std::string title;
        Warlock();
        Warlock(const Warlock &other);
        Warlock &operator=(const Warlock &other);
    public:
        Warlock(const std::string &name, const std::string &title);
        const std::string getName(void) const;
        const std::string getTitle(void) const;
        void setTitle(const std::string &title);
        void introduce(void) const;
        ~Warlock();
};