#include <iostream>
#include <cmath>

int main()
{
    int n;
    do
    {
        std::cout << "Print e until which digit?" << std::endl;
        std::cin >> n;
        
        if(n > 100)
        {
            std::cerr << "Cannot print more than 100 digits of e." << std::endl;
        }
    }
    while (n > 100);

    std::cout.precision(n);
    std::cout << e;

    return 0;
}