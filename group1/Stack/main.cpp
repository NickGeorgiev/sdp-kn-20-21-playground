#include "MathExpression.h"

int main()
{
    MathExpr e;
    e.parse("5+((2+5)*7)-4");
    std::cout << e.solve();

    return 0;
}
