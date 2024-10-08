#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

int main()
{
    size_t N = 0;
    std::cin >> N;
    
    std::vector<int> pumps;
    
    for (size_t i = 0; i < N; i++)
    {
        int num = 0;
        std::cin >> num;
        pumps.push_back(num);
    }
    
    size_t maxLiters = 0;
    
    for (size_t i = 0; i < pumps.size() - 1; i++)
    {
        for (int j = pumps.size() - 1; j > i; j--)
        {
            size_t liters = std::min(pumps[i], pumps[j]) * (j - i);
            maxLiters = std::max(maxLiters, liters);
        }
    }
    
    std::cout << maxLiters << std::endl;
    
    return 0;
}