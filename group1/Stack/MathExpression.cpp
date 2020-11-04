#include "MathExpression.h"

void MathExpr::parse(const std::string& expr)
{
    for(size_t i = 0; i < expr.size(); ++i)
    {
        if(is_operator(expr[i]) || expr[i] == '(' && i < expr.size() - 1){
            symbols.push(expr[i]);
        }
        else if(expr[i] >= '0' && expr[i] <= '9' && i < expr.size() - 1){
            result.push_back(expr[i]);
        }
        else if(expr[i] == ')' && i < expr.size() - 1){
            while(symbols.top() != '(')
            {
                result.push_back(symbols.top());
                symbols.pop();
            }
            symbols.pop();
        }
        else if(i == expr.size() - 1){
            if(expr[i] >= '0' && expr[i] <= '9'){
                result.push_back(expr[i]);

                while(!symbols.empty())
                {
                    result.push_back(symbols.top());
                    symbols.pop();
                }
            }
            if(expr[i] == ')'){
                while(symbols.top() != '(')
                {
                    result.push_back(symbols.top());
                    symbols.pop();
                }
                symbols.pop();
            }
        }
        else return;
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
            temp = operate(temp, numbers.top(), result[i]);
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

std::vector<char> MathExpr::get_result() const
{
    return result;
}