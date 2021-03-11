#include <iostream>
#include <cmath>

int printFib(int n, int a, int b)
{
    std::cout << a << std::endl;
    if (n <= 1)
    {
        return a;
    }
    else
    {
        return printFib(n-1, b, a + b); 
    }
}

int main()
{
   printFib(20, 0, 1);
}