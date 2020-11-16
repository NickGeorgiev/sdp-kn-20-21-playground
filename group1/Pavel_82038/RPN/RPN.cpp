#define DOCTEST_CONFIG_IMPLEMENT

#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <assert.h>
#include <functional>
#include "../Stack/Stack.h"
#include "../../../shared/specs/doctest.h"

//Convert infix expression to
//Reverse Polish Notation


bool isOperand(const char c)
{
    return c >= '0' && c <= '9';
}

bool isOperator(const char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

size_t priority(const char c)
{
    switch(c)
    {
        case '+':
            return 1;
            break;
        case '-':
            return 1;
            break;
        case '*':
            return 2;
            break;
        case '/':
            return 2;
            break;
        case '^':
            return 3;
            break;
        default:
            return 0;
            break;
    }
}

bool isExpectedSymbol(const char c)
{
    return isOperand(c) || isOperator(c) || c == '(' || c == ')' || c == ' ' || c == '\t';
}

bool isValidExpression(const std ::string &expression)
{
    Stack<char> parentheses;

    
    /*for (size_t i = 0; i < expression.size(); i++)
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
    }*/
    
    size_t i = 0;
    for (char c: expression)
    {
        if (!isExpectedSymbol(c))
        {
            return false;
        }

        if (isOperator(c))
        {
            if (&c == &*expression.begin() || &c == &expression.back() || isOperator(expression[i + 1]))
            {
                return false;
            }
        }

        if (c == '(')
        {
            parentheses.push(c);
        }
        else if (c == ')' && !parentheses.empty())
        {
            parentheses.pop();
        }
        else if (c == ')' && parentheses.empty())
        {
            return false;
        }
        
        i++;
    }
    
    if (!parentheses.empty())
        return false;

    return true;
}

std::string convertExpression(const std ::string &expression)
{
    assert(isValidExpression(expression));

    Stack<char> operators;
    std::string postfix;

    for (char c: expression)
    {
        if (isOperand(c))
        {
            postfix.push_back(c);
        }
        else if (c == '(')
        {
            operators.push(c);
        }
        else if (isOperator(c))
        {
            while (!operators.empty() && priority(operators.top()) >= priority(c))
            {
                postfix.push_back(operators.top());
                operators.pop();
            }
            operators.push(c);
        }
        else if (c == ')')
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

void func(Stack<int>& numbers, std::function<int(int, int)> operation)
{
    int b = numbers.top();
    numbers.pop();
    int a = numbers.top();
    numbers.pop();
    numbers.push(operation(a, b));
}

int intPow(int a, int b)
{
    if (b == 0)
    {
        return 1; 
    }
    else if (b < 1)
    {
        return 0;
    }
    else
    {
        return a * intPow(a, b - 1);
    }
}

std::function<int(int, int)> power = intPow;

void operate(Stack<int>& numbers, char op)
{
    switch(op)
    {
        case '+':
            func(numbers, [](int a, int b)->int{ return a + b;});
            break;
        case '-':
            func(numbers, [](int a, int b)->int{ return a - b;});
            break;
        case '*':
            func(numbers, [](int a, int b)->int{ return a * b;});
            break;
        case '/':
            func(numbers, [](int a, int b)->int{ return a / b;});
            break;
        case '^':
            func(numbers, power);
            break;
    }
}

int calculateRPN(const std::string &expression)
{
    Stack<int> numbers;

    for (char c: expression)
    {
        int result;

        if (isOperand(c))
        {
            numbers.push(c - '0');
        }
        else
        {
            operate(numbers, c);
        }
    }

    return numbers.top();;
}
