#include <iostream>
#include <stack>
int eminN(int n, int x)
{
    if (n == 0)
        return 1;
    else if (n == 1)
        return 2 * x;
    else
    {
        return 2 * x * eminN(n - 1, x) + 2 * (n - 1) * eminN(n - 2, x);
    }
}
int eminNIter(int n, int x)
{
    std::stack<int> s;
    s.push(1);
    s.push(2 * x);
    while (n > 1 && !s.empty())
    {
        int first = s.top();
        s.pop();
        int second = s.top();
        s.pop();
        s.push(first);
        s.push(2 * x * first + 2 * (n - 1) * second);
        n--;
    }
    return s.top();
}

int main()
{
    std::cout << eminN(15, 2) << std::endl;
    std::cout << eminNIter(15, 2) << std::endl;
    return 0;
}