// Example program
#include <iostream>
#include <string>
#include <cwctype>

const char* clearString(std::string str)
{
    for (int i = str.length() - 1; i >= 0; i--)
    {
        if (!isdigit(str[i]) && str[i] != ',')
        {
            str.erase(i, 1);
        }
    }
    return str.c_str();
}

int main()
{
    std::string str = "688,13 €";

    std::cout << clearString(str);
}