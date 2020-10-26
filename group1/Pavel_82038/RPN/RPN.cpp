#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <assert.h>
#include <math.h>

//Convert infix expression to
//Reverse Polish Notation

bool isOperand(const char c)
{
    return c - '0' >= 0 && c - '9' <= 9;
}

bool isOperator(const char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

size_t priority(const char c)
{
    if (c == '+' || c == '-')
        return 1;
    if (c == '*' || c == '/')
        return 2;
    if (c == '^')
        return 3;

    return 0;
}

bool isExpectedSymbol(const char c)
{
    return isOperand(c) || isOperator(c) || c == '(' || c == ')' || c == ' ' || c == '\t';
}

bool isValidExpression(const std ::string &expression)
{
    std::stack<char> parentheses;

    for (size_t i = 0; i < expression.size(); i++)
    {
        if (!isExpectedSymbol(expression[i]))
            return false;

        if (isOperator(expression[i]))
        {
            if (i == 0 || i == expression.size()-1 || isOperator(expression[i + 1]))
                return false;
        }

        if (expression[i] == '(')
        {
            parentheses.push(expression[i]);
        }
        else if (expression[i] == ')' && !parentheses.empty())
        {
            parentheses.pop();
        }
        else if (expression[i] == ')' && parentheses.empty())
        {
            return false;
        }
    }

    if (!parentheses.empty())
        return false;

    return true;
}

std::string convertExpression(const std ::string &expression)
{
    assert(isValidExpression(expression));

    std::stack<char> operators;
    std::string postfix;

    for (size_t i = 0; i < expression.size(); i++)
    {
        if (isOperand(expression[i]))
        {
            postfix.push_back(expression[i]);
        }
        else if (expression[i] == '(')
        {
            operators.push(expression[i]);
        }
        else if (isOperator(expression[i]))
        {
            while (!operators.empty() && priority(operators.top()) >= priority(expression[i]))
            {
                postfix.push_back(operators.top());
                operators.pop();
            }
            operators.push(expression[i]);
        }
        else if (expression[i] == ')')
        {
            while (operators.top() != '(')
            {
                postfix.push_back(operators.top());
                operators.pop();
            }
            operators.pop();
        }
    }

    while (!operators.empty())
    {
        postfix.push_back(operators.top());
        operators.pop();
    }

    return postfix;
}

int calculateRPN(const std::string &expression)
{
    std::stack<int> numbers;

    for (size_t i = 0; i < expression.size(); i++)
    {
        int result;

        if (isOperand(expression[i]))
        {
            numbers.push(expression[i] - '0');
        }
        else if (expression[i] == '+')
        {
            int b = numbers.top();
            numbers.pop();
            int a = numbers.top();
            numbers.pop();
            numbers.push(a + b);
        }
        else if (expression[i] == '-')
        {
            int b = numbers.top();
            numbers.pop();
            int a = numbers.top();
            numbers.pop();
            numbers.push(a - b);
        }
        else if (expression[i] == '*')
        {
            int b = numbers.top();
            numbers.pop();
            int a = numbers.top();
            numbers.pop();
            numbers.push(a * b);
        }
        else if (expression[i] == '/')
        {
            int b = numbers.top();
            numbers.pop();
            int a = numbers.top();
            numbers.pop();
            numbers.push(a / b);
        }
        else if (expression[i] == '^')
        {
            int b = numbers.top();
            numbers.pop();
            int a = numbers.top();
            numbers.pop();
            numbers.push(pow(a, b));
        }
    }

    return numbers.top();;
}

int main()
{
    std::cout << convertExpression("2^3");
    std::cout << '\n';
    std::cout << calculateRPN(convertExpression("2^3"));
    std::cout << '\n';
    std::cout << convertExpression("5+7+1+2");
    std::cout << '\n';
    std::cout << calculateRPN(convertExpression("5+7+1+2"));
    std::cout << '\n';
    std::cout << convertExpression("((1+2)*3/(1+2))");
    std::cout << '\n';
    std::cout << calculateRPN(convertExpression("((1+2)*3/(1+2))"));

    return 0;
}
