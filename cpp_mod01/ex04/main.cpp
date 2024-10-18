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
    std::string s1 = argv[2];
    std::string s2 = argv[3];
    std::string line;
    std::ifstream file(argv[1]);
    size_t pos;
    size_t newpos;
    std::string filenew = argv[1] + "new";
    std::ofstream outfile(filenew);
    if (file.is_open() == false)
    {
        std::cout << "Opening file error" << std::endl;
        return 1;
    }
    while (std::getline(file, line))
    {
        pos = 0;
        newpos = 0;
        while ((newpos = line.find(s1, pos)) != std::string::npos)
        {
            outfile << line.substr(pos, newpos - pos);
            outfile << s2;
            pos = newpos + s1.length();
        }
        outfile << std::endl;
    }
    file.close();
    outfile.close();
    return 0;
}
