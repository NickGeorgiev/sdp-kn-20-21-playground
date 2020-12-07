#include <string>
#include <functional>
#include <iostream>
#include <stack>

class PostfixExpression
{

private:
    std::string expression;

public:
    PostfixExpression(const std::string &infixExpression)
    {
        std::stack<char> stack = std::stack<char>();

        for (const char &symbol : infixExpression)
        {

            if (symbol == '(')
            {
                stack.push(symbol);
            }

            else if (symbol == ')')
            {
                while (stack.top() != '(')
                {
                    expression.push_back(stack.top());
                    stack.pop();
                }
                if (stack.top() == '(')
                {
                    stack.pop();
                }
                else
                {
                    throw std::exception();
                }
            }

            else if (isOperation(symbol))
            {
                while (!stack.empty() && stack.top() != '(' && isMoreImportantThan(stack.top(), symbol))
                {
                    expression.push_back(stack.top());
                    stack.pop();
                }
                stack.push(symbol);
            }

            else if (isNumber(symbol))
            {
                expression.push_back(symbol);
            }
            
            else
            {
                throw std::exception();
            }
        }

        while (!stack.empty())
        {
            expression.push_back(stack.top());
            stack.pop();
        }
    }

    void print() const
    {
        std::cout << expression << std::endl;
    }

    int solve() const
    {
        std::stack<int> stack = std::stack<int>();
        for (const char &symbol : expression)
        {
            if (isNumber(symbol))
            {
                stack.push(toInt(symbol));
            }
            else if (isOperation(symbol))
            {
                if (stack.size() < 2)
                {
                    throw std::exception();
                }

                int second = stack.top();
                stack.pop();

                int first = stack.top();
                stack.pop();

                stack.push(getFunctionFromOperation(symbol)(first, second));
            }
        }

        return stack.top();
    }

private:
    static bool isOperation(const char &symbol)
    {
        switch (symbol)
        {
        case '+':
            return true;
        case '-':
            return true;
        case '*':
            return true;
        case '/':
            return true;
        default:
            return false;
        }
    }

    static bool isNumber(const char &symbol)
    {
        return symbol >= '0' && symbol <= '9';
    }

    static int toInt(const char &number)
    {
        return number - '0';
    }

    static bool isMoreImportantThan(const char &operation1, const char &operation2)
    {
        if (operation1 == '-' || operation1 == '+')
        {
            if (operation2 != '*' && operation2 != '/')
            {
                return true;
            }
            return false;
        }

        if (operation2 == '*' || operation2 == '/')
        {
            if (operation1 != '+' && operation1 != '-')
            {
                return true;
            }
            return false;
        }

        return true;
    }

    static std::function<int(int, int)> getFunctionFromOperation(const char &symbol)
    {
        switch (symbol)
        {
        case '+':
            return [](int a, int b) -> int { return a + b; };
        case '-':
            return [](int a, int b) -> int { return a - b; };
        case '*':
            return [](int a, int b) -> int { return a * b; };
        case '/':
            return [](int a, int b) -> int { return a / b; };
        default:
            break;
        }
    }
};

int main()
{
    std::string expression = std::string("3+4*2+1");

    PostfixExpression postfixExpression = PostfixExpression(expression);

    postfixExpression.print();

    std::cout << postfixExpression.solve() << std::endl;
}
