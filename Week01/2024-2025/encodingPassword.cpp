#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

int main()
{
    std::string str;
    std::cin >> str;
    
    size_t idx = 0;
    while (idx < str.size())
    {
        char ch = str[idx];
        size_t counter = 0;
        
        while (str[idx] == ch)
        {
            counter++;
            idx++;
        }
        
        std::cout << counter << ch;
    }
    
    return 0;
}