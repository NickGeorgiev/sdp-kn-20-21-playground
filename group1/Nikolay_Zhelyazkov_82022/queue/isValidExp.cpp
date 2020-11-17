#include <queue>
#include <iostream>
#include <string>

bool isValidExp(const std::string &exp)
{
    std::queue<char> open;
    std::queue<char> close;
    if (exp[0] == ')' || exp[exp.size() - 1] == '(')
    {
        return false;
    }
    for (char el : exp)
    {
        if (el == '(')
        {
            open.push(el);
        }
        else if (el == ')')
        {
            close.push(el);
        }
    }
    if (open.empty() && close.empty())
    {
        return true;
    }
    while (!open.empty() && !close.empty())
    {
        open.pop();
        close.pop();
    }
    return open.empty() && close.empty();
}

int main()
{
    std::cout << isValidExp("(3*(5+(9*3+(*3(6+9))))+9*3)1");
    return 0;
}