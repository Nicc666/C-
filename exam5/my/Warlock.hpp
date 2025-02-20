
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
        std::string &getName(void);
        std::string &getTitle(void);
        void setTitle(const std::string &title);
        Warlock(const std::string &name, const std::string &title);
        ~Warlock();
};

