#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <set>

void numGetter(std::string line, int &result)
{

    std::string token{""};
    for (int i{0}; i < line.size(); i++)
    {
        std::set<char> wsc{'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'y', 'z', 'x', ' '};
        if (!wsc.contains(line[i]))
        {
            token += line[i];
        }
    }

    int converted = std::stoi(token);
    int ones = converted % 10;
    int tens{0};

    if (converted > 10)
    {
        while (converted >= 10)
        {
            converted /= 10;
        }
        tens = converted;
    }

    if (tens == 0)
    {
        result += (ones * 10) + ones;
    }
    else
    {
        result += (tens * 10) + ones;
    }
}

int main()
{

    std::string line;

    int result{};

    std::ifstream ifile;

    ifile.open("lines.txt", std::ios::app);

    while (ifile >> line)
    {
        numGetter(line, result);
    }

    ifile.close();

    std::cout << result << '\n';

    return 0;
}