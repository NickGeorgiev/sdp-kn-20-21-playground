//g++ convertToBinAndtoHex.cpp
#include <iostream>
#include <stack>

void toBinary(int n)
{
    std::stack<int> s;
    while (n != 0)
    {
        s.push(n % 2);
        n /= 2;
    }
    while (!s.empty())
    {
        std::cout << s.top();
        s.pop();
    }
    std::cout << std::endl;
}
void toHex(int n)
{
    std::stack<char> s;
    int res;
    char c;
    while (n != 0)
    {
        res = n % 16;
        if (res >= 10)
        {
            c = ('A' + res) - 10;
            s.push(c);
        }
        else
        {
            s.push((char)(res + '0'));
        }
        n /= 16;
    }
    while (!s.empty())
    {
        std::cout << s.top();
        s.pop();
    }
    std::cout << std::endl;
}

int main()
{
    int number;
    std::cin >> number;
    toBinary(number);
    toHex(number);
    return 0;
}