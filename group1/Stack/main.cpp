#include "MathExpression.h"

int main()
{
    MathExpr e;
    e.parse("3*4+2+5*2");

    for(char c : e.get_result())
    {
        std::cout << c << " ";
    }std::cout << std::endl;
    
    std::cout << e.solve();

    return 0;
}
//  
// 
//