#include <stack>
#include <string>
#include <iostream>
#include <algorithm>
std::stack<int> mergeStack(std::stack<int> s1, std::stack<int> s2)
{
    //9 5 3 1
    //8 7 6 5 3
    //9 8 7 6 5 5 3 3 1
    std::stack<int> result;
    std::stack<int> temp;
    while (!s2.empty() && !s1.empty())
    {
        if (s2.top() > s1.top())
        {
            temp.push(s2.top());
            s2.pop();
        }
        else
        {
            temp.push(s1.top());
            s1.pop();
        }
    }
    while (!s1.empty())
    {
        temp.push(s1.top());
        s1.pop();
    }
    while (!s2.empty())
    {
        temp.push(s2.top());
        s2.pop();
    }
    while (!temp.empty())
    {
        result.push(temp.top());
        temp.pop();
    }
    return result;
}
void print(std::stack<int> s)
{
    while (!s.empty())
    {
        std::cout << s.top() << " ";
        s.pop();
    }
}
// $| @ -> op
// number
//exp
//exp = num|(exp op exp)

bool isOP(const char s)
{
    return s == '$' || s == '@';
}
bool isNum(const char c)
{
    return c >= '0' && c <= '9';
}
int toNum(const char s)
{
    return (int)s - '0';
}

std::string decode(const std::string &s)
{
    //std::string res;
    std::stack<int> repNums;
    std::stack<std::string> decode;
    std::string temp;
    int repN = 0;

    for (char c : s)
    {
        if (isdigit(c))
        {
            repN = repN * 10 + toNum(c);
        }
        if (isalpha(c))
        {
            temp += c;
        }
        if (c == '(')
        {
            repNums.push(repN);
            decode.push(temp);
            repN = 0;
            temp = "";
        }
        if (c == ')')
        {
            int repTop = repNums.top();
            repNums.pop();
            std::string repS = "";
            for (size_t i = 0; i < repTop; i++)
            {
                repS += temp;
            }
            temp = decode.top() + repS;
            decode.pop();
        }
    }
    return temp;
}

char toChar(int el)
{
    return '0' + el;
}
int calculate(const std::string &s)
{
    //(2@(3$4))
    std::stack<char> st;
    char l, r, op;
    char res;
    for (char c : s)
    {
        if (isOP(c) || isdigit(c))
        {
            st.push(c);
        }
        else if (c == ')')
        {
            r = st.top();
            st.pop();
            op = st.top();
            st.pop();
            l = st.top();
            st.pop();
            if (op == '@')
            {
                int el = (toNum(l) + toNum(r)) % 10;
                res = toChar(el);
            }
            else if (op == '$')
            {
                int el = std::min(toNum(l), toNum(r));
                res = toChar(el);
            }
            st.push(res);
        }
    }
    res = st.top();
    st.pop();
    return toNum(res);

    // std::stack<char> exp;
    // std::stack <int>res;
    // if (isNum(s[0]))
    // {
    //     return toNum(s[0]);
    // }
    // else if (s[0] == '(')
    // {
    //     int res = 0;
    //     exp.push(s[0]);
    //     for (size_t i = 1; i < s.size(); i++)
    //     {
    //         if (s[i] == '(' || isOP(s[i]) || isNum(s[i]))
    //         {
    //             exp.push(s[i]);
    //         }

    //         else if (s[i] == ')')
    //         {
    //             while (exp.top() != '(' && !exp.empty())
    //             {
    //                 bool right = false;
    //                 int r = 0;
    //                 char op = '0';
    //                 int l = 0;
    //                 if (isNum(exp.top()) && !right)
    //                 {
    //                     r = toNum(exp.top());
    //                     exp.pop();
    //                     right = true;
    //                 }
    //                 else if (isOP(exp.top()))
    //                 {
    //                     op = exp.top();
    //                     exp.pop();
    //                 }
    //                 else if (isNum(exp.top()) && right)
    //                 {
    //                     l = toNum(exp.top());
    //                     exp.pop();
    //                     right = false;
    //                 }
    //                 if (op == '@')
    //                 {
    //                     op = '0';
    //                     res = (l + r) % 10;
    //                 }
    //                 else if (op == '$')
    //                 {
    //                     op = '0';
    //                     res = std::min(l, r);
    //                 }
    //             }
    //         }
    //     }
}

int power(char c)
{
    switch (c)
    {
    case '+':
        return 0;
        break;
    case '-':
        return 0;
        break;
    case '*':
        return 1;
        break;
    case '/':
        return 1;
        break;
    case '^':
        return 2;

    default:
        throw std::invalid_argument("Eror operator");
        return -1;
        break;
    }
}
bool isItExpOp(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}
std::string translate(const std::string &s)
{
    std::string result;
    std::stack<char> st;
    st.push('(');
    for (char c : s)
    {
        if (isdigit(c))
        {
            result.push_back(c);
        }
        else if (c == '(')
        {
            st.push(c);
        }
        else if (c == ')')
        {
            while (st.top() != '(')
            {
                result.push_back(st.top());
                st.pop();
            }
        }
        else if (isItExpOp(c))
        {
            char t = st.top();
            st.pop();
            while (t != '(' && power(t) >= power(c))
            {
                result.push_back(t);
                t = st.top();
                st.pop();
            }
            st.push(t);
            st.push(c);
        }
    }
    while (st.top() != '(')
    {
        result.push_back(st.top());
        st.pop();
    }

    return result;
}
bool isLogicOp(char c)
{
    return c == '~' || c == '+' || c == '*';
}
bool exp(const std::string &str)
{
    std::string res = str;
    if (str[str.size() - 1] != ')')
    {
        res.push_back(')');
    }

    std::stack<char> s1;
    std::stack<char> s2;
    for (char c : res)
    {
        if (c == 't' || c == 'f')
        {
            s1.push(c);
        }
        else if (isLogicOp(c))
        {
            s2.push(c);
        }
        else if (c == ')')
        {
            char x, y, res;
            switch (s2.top())
            {
            case '~':
                x = s1.top() == 't' ? 'f' : 't';
                s1.pop();
                s1.push(x);
                break;
            case '+':
                x = s1.top();
                s1.pop();
                y = s1.top();
                s1.pop();
                res = (x == 'f' && y == 'f') ? 'f' : 't';
                s1.push(res);
                break;
            case '*':
                x = s1.top();
                s1.pop();
                y = s1.top();
                s1.pop();
                s1.push(res);
                res = (x == 't' && y == 't') ? 't' : 'f';
                break;
            default:
                throw std::invalid_argument("Error logic operation");
                break;
            }
        }
    }
    return s1.top() == 't';
}