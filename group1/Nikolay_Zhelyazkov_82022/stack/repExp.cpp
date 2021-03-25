#include <string>
#include <stack>
#include <iostream>
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

bool isItLetter(char c)
{
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}
//3[ab]2[ac3[bg]]
//ababab acbgbgbg acbgbgbg

std::string makeExp(const std::string &exp)
{
    std::stack<int> num;
    std::stack<char> symbols;
    std::string res = "";
    std::string temp = "";
    bool level = false;
    bool inside = false;
    bool normal = true;
    int counter = 0;
    for (size_t i = 0; i < exp.size(); ++i)
    {
        if (isItNumber(exp[i]))
        {
            if (i > 0)
            {
                int k = i-1;
                if (isItLetter(exp[k]))
                {
                    inside = true;
                    normal = false;
                }
                else if (exp[k] == ']')
                {
                    inside = false;
                    normal = true;
                }
            }

            // while (isItNumber(exp[k]))
            // {
            //     --k;
            // }

            num.push(fromCharToInt(exp[i]));
        }
        else if (exp[i] == '[' || isItLetter(exp[i]))
        {
            if (exp[i] == '[')
            {
                 counter++;
                // if (counter > 1)
                // {
                //     level = true;
                // }
            }
            symbols.push(exp[i]);
        }
        else if (exp[i] == ']')
        {
            if (counter >= 1  && inside)
            {
                while (symbols.top() != '[' && !symbols.empty())
                {
                    temp.insert(temp.begin(), symbols.top());
                    symbols.pop();
                }
                symbols.pop();
                std::string t = temp;
                for (size_t j = 0; j < num.top() - 1; ++j)
                {
                    temp += t;
                }
                t = "";
                counter--;
                if (counter == 0)
                {
                   // level = false;
                    res += temp;
                }
                num.pop();
            }
            else if (counter >= 1  && !inside)
            {
                temp = "";
                while (symbols.top() != '[' && !symbols.empty())
                {
                    temp.insert(temp.begin(), symbols.top());
                    symbols.pop();
                }
                symbols.pop();
                if (!num.empty())
                {
                    for (size_t j = 0; j < num.top(); ++j)
                    {
                        res += temp;
                    }
                    num.pop();
                    temp = "";
                }
                counter--;
            }
        }
    }
    // res = temp;
    return res;
    
}
int main()
{
    //abbgbg
    //chastichen uspeh
    std::string temp = "3[ab2[jg]]3[gz]2[ds]";
    std::cout << makeExp(temp);
    // temp.insert(temp.begin(), 'f');
    // std::cout << temp << std::endl;
}