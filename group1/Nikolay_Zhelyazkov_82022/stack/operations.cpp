#include "operations.h"
#include "cmath"
double Operations::Plus(double n, double prev)
{
    return prev + n;
}
double Operations::Minus(double n, double prev)
{
    return prev - n;
}
double Operations::Multiply(double n, double prev)
{

    return prev * n;
}
double Operations::Division(double n, double prev)
{
    return prev / n;
}
double Operations::Step(double step, double prev)
{
    return pow(prev, step);
}

double Operations::Operate(char c, double n, double prev)
{
    switch (c)
    {
    case '+':
        return Operations::Plus(n, prev);
        break;
    case '-':
        return Operations::Minus(n, prev);
        break;
    case '*':
        return Operations::Multiply(n, prev);
        break;
    case '/':
        return Operations::Division(n, prev);
        break;
    case '^':
        return Operations::Step(n, prev);
        break;
    default:
        throw "Error operator";
        break;
    }
}
