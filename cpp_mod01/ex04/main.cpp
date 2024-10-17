#include <string>
#include <iostream>
#include <fstream>

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cout << "Parameter input error" << std::endl;
        return 1;
    }
    std::ifstream file(argv[1]);
    if (file.is_open() == true)
        {
        std::cout << "Parameter input error" << std::endl;
        return 1;
    }
    return 0;
}
