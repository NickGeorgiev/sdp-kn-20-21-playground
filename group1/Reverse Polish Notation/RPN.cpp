#include "RPN.h"
#include <stack>


RPN::RPN(const std::string& _input) : input(_input) {}

void RPN::convert()
{
    std::stack<char> s;

    for(size_t i = 0; i < input.size(); ++i)
    {
        if(input[i] == '('){
            s.push(input[i]);
        }
        else if(isDigit(input[i])){
            output.push_back(input[i]);
        }
        else if(isOperator(input[i])){
            if(isOperator(s.top()) && preority(s.top()) > preority(input[i])){
                while(preority(s.top()) >= preority(input[i]))
                {
                    output.push_back(s.top());
                    s.pop();
                }
                s.push(input[i]);
            }
            else{
                s.push(input[i]);
            }
        }
        else if (input[i] == ')')
        {
            while(s.top() != '(')
            {
                output.push_back(s.top());
                s.pop();
            }
            s.pop();
        }
    }
}

int RPN::calculate() const
{
    std::stack<int> s;

    for(size_t i = 0; i < output.size(); ++i)
    {
        if(isDigit(output[i])){
            s.push(toInt(output[i]));
        }
        if(isOperator(output[i])){
            int a = s.top(); s.pop();
            int b = s.top(); s.pop();

            s.push(operate(a, b, output[i]));
        }
    }

    return s.top();
}

bool RPN::isOperator(const char& c) const
{
    return c == '+' || c == '-' || c == '*' || c == '/';
}

int RPN::preority(const char& c) const
{
    switch(c)
    {
        case '+': return 1;
        case '-': return 1;
        case '*': return 2;
        case '/': return 2;
        case '(': return 0;
        default: return -1;
    }
}

int RPN::operate(const int& a, const int& b, const char& c) const
{
    switch(c)
    {
        case '+': return a + b;
        case '*': return a * b;
        case '-': return a - b;
        case '/': return a / b;
        default: return 0;
    }
}

bool RPN::isDigit(const int& x) const
{
    return x >= '0' && x <= '9';
}

int RPN::toInt(const char& c) const
{
    return c - '0';
}
