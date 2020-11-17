#include <iostream>
#include <stack>
#include <string>
#include <exception>
#include "operations.h"
bool isItNumber(char c)
{
    return c >= '0' && c <= '9';
}
int fromCharToInt(char c)
{
    if (!isItNumber(c))
    {
        throw "Not a number";
    }
    return (int)c - '0';
}
bool isOperator(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}
//funkciq s postavqne na skobi
std::string normalToRevPolNot(const std::string &exp)
{
    std::stack<char> s;
    std::string newS;
    for (char symbol : exp)
    {
        if (isItNumber(symbol))
        {
            newS.push_back(symbol);
        }
        else
        {
            s.push(symbol);
        }
        while (s.top() == ')' && s.top() != '(')
        {
            s.pop();
            newS.push_back(s.top());
            s.pop();
        }
    }
    return newS;
}
//funkciq bez postavqne na skobi
std::string transform(const std::string &str)
{
    std::stack<char> stack;
    std::string newStr;
    std::string result;

    if (str[0] != '(' || str[str.size() - 1] != ')')
    {
        newStr.push_back('(');
        for (char s : str)
        {
            newStr.push_back(s);
        }
        newStr.push_back(')');
    }
    else
    {
        newStr = str;
    }

    for (size_t i = 0; i < newStr.size(); ++i)
    {

        if (isItNumber(newStr[i]))
        {
            result.push_back(newStr[i]);
        }
        else if (isOperator(newStr[i]) && isOperator(stack.top()))
        {
            i--;
            result.push_back(stack.top());
            stack.pop();
        }
        else if (isOperator(newStr[i]) || newStr[i] == '(')
        {
            stack.push(newStr[i]);
        }
        else if (newStr[i] == ')')
        {
            while (stack.top() != '(' && !stack.empty())
            {
                result.push_back(stack.top());
                stack.pop();
            }
            stack.pop();
        }
        else
        {
            return "Error symbol";
        }
        
    }
    return result;
}

double result(std::string symbols)
{

    std::stack<double> results;
    double res = 0;
    int count = 0;
    while (count <= symbols.size())
    {
        if (isItNumber((symbols[count])))
        {
            results.push(fromCharToInt(symbols[count]));
            count++;
        }
        else
        {
            while (!results.empty())
            {
                res = Operations::Operate(symbols[count], results.top(), res);
                results.pop();
            }
            count++;
        }
    }
    return res;
}

int main()
{
    // std::string symbols = {'3', '4', '8', '+', '7', '+', '2', '*'};

    //std::cout << result(symbols);
    std::string r = "3+2*3-4/2";
    r = transform(r);
    std::cout << r << std::endl;
    // r = normalToRevPolNot(r);
    // std::cout << r << std::endl;
     std::cout << result(r) << std::endl;
    // std::cout << result("35+3-2*");
}
