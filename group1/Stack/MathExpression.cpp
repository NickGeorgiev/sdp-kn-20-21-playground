#include "MathExpression.h"

void MathExpr::parse(const std::string& _expr)
{
    std::string expr = "(";
    for(size_t i = 0; i < _expr.size(); ++i)
    {
        expr.push_back(_expr[i]);
    }
    expr.push_back(')');

    for(size_t i = 0; i < expr.size(); ++i)
    {
        bool make_step = true;

        if(is_operator(expr[i]) && is_operator(symbols.top())){
            result.push_back(symbols.top());
            symbols.pop();
            make_step = false;
            --i;
        }

        if((expr[i] == '(' || is_operator(expr[i])) && make_step){
            symbols.push(expr[i]);
            make_step = false;
        }

        if(expr[i] >= '0' && expr[i] <= '9' && make_step) {
            result.push_back(expr[i]);
            make_step = false;
        }

        if(expr[i] == ')' && make_step){
            while(symbols.top() != '(' || symbols.empty())
            {
                result.push_back(symbols.top());
                symbols.pop();
            }
            symbols.pop();
        }
    }
}

// double MathExpr::solve()
// {
//     return answer;
// }

std::vector<char> MathExpr::get_result () const
{
    return result;
}

bool MathExpr::is_operator(const char& c) const
{
    return c == '+' || c == '-' || c == '*' || c == '/';
}