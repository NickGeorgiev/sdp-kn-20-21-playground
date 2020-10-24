#include "MathExpression.h"


int main()
{
    MathExpr e;
    e.parse("5+((2+5)*7)-4");

    for(char c : e.get_result())
    {
        std::cout << c << " ";
    }std::cout << std::endl;

    //std::cout << e.solve() << std::endl;

    return 0;
}
