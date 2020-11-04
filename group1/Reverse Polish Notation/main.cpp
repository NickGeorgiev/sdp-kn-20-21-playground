#include "RPN.h"
#include<iostream>

int main()
{
    std::string s;
    std::getline(std::cin, s);

    RPN expr(s);
    expr.convert();
    std::cout << expr.calculate();


    return 0;
}