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

double MathExpr::solve()
{
    std::stack<double> numbers;

    for(size_t i = 0; i < result.size(); ++i)
    {
        if(result[i] >= '0' && result[i] <= '9'){
            numbers.push(result[i] - '0');
        }

        if(is_operator(result[i])){
            if(numbers.size() < 2) throw "Something is wrong.\n";

            double temp = numbers.top();
            numbers.pop();
            temp = operate(numbers.top(), temp, result[i]);
            numbers.pop();

            numbers.push(temp);
        }
    }

    if(numbers.size() > 1) throw "Something is wrong.\n";

    return numbers.top();
}

bool MathExpr::is_operator(const char& c) const
{
    return c == '+' || c == '-' || c == '*' || c == '/';
}

double MathExpr::operate(const int& a, const int& b, const char& c) const
{
    if(c == '+') return a + b;
    if(c == '-') return a - b;
    if(c == '*') return a * b;
    if(c == '/') return a / b;

    throw "Wrong operator\n";
}
