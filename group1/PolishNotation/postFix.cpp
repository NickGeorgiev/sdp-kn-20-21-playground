#include"postFix.h"
#include<iostream>
#include<cassert>
#include<cmath>

bool PostFix::isDigit(char x)
{
    return x >= '0' && x <= '9';
}

bool PostFix::isOperator(char x)
{
    return x == '*' || x == '/' || x == '+' || x == '-' || x == '^';
}

int PostFix::priorityOperator(char x)
{   
    if(x == '^') return 3;
    else if(x == '*' || x == '/') return 2;
    else if(x == '+' || x == '-') return 1;
    else return 0;
}

bool PostFix::isOpeningBracket(char x)
{
    return x == '(';
}

bool PostFix::isMixedOpeningBracket(char x)
{
    return x == '(' || x == '[' || x == '{';
}

bool PostFix::isMixedClosingBracket(char x)
{
    return x == ')' || x == ']' || x == '}';
}

bool isClosingBracket(char x)
{
    return x == ')';
}

char brackets(char x)
{
    switch(x)
    {
        case ')':return '(';
        case ']':return '[';
        case '}':return '{';
    }
}

PostFix::PostFix(std::string expresion):expresion(expresion){}

//ex.18.2
bool PostFix::correctBracket() 
{
    for(char element: expresion)
    {
        if(isOpeningBracket(element)) sym.push(element);
        else if(isClosingBracket(element))
        {
            if(sym.empty()) 
            {
                return false; 
            }
            sym.pop();
        }
    }
   return sym.empty();
}

//ex.18.3
bool PostFix::advancedCorrect()
{
    for(char element: expresion)
    {
        if(isMixedOpeningBracket(element)) sym.push(element);
        else if(isMixedClosingBracket(element))
        {
            if(sym.empty() || sym.top() != brackets(element)) return false;
            sym.pop();
        }
    }
    return sym.empty();
}

bool PostFix::correct()
{
    if(correctBracket())
    {
        for(char element: expresion)
        {
            if(!(isDigit(element) || isOperator(element)
            || isOpeningBracket(element) || isClosingBracket(element))) return false;
        }
        return true;
    }
    return false;
}

void PostFix::make()
{
    assert(correct());
    for(char element: expresion)
    {
        if(isDigit(element)) num.push_back(element);
        else if(isOpeningBracket(element)) sym.push(element);
        else if(isOperator(element))
        {
            while(!sym.empty() && priorityOperator(sym.top()) >= priorityOperator(element))
            {
                num.push_back(sym.top());
                sym.pop();
            }
            sym.push(element);
        }
        else if(isClosingBracket(element))
        {
            while(!sym.empty() && !isClosingBracket(element))
            {
                num.push_back(sym.top());                
                sym.pop();
            }
            if(isClosingBracket(sym.top())) sym.pop();
        }
    }
    while(!sym.empty())
    {
        num.push_back(sym.top());
        sym.pop();
    }
    for(char i:num)
    {
        std::cout<<i;
    }
    std::cout<<"--->";    
}

int PostFix::calculating()
{
    make();
    for(char i: num)
    {
        if(isDigit(i))
        {
            sym.push(i);
        }
        else if(isOperator(i))
        {
            int helper = sym.top() - '0';
            sym.pop();
            if(i == '*')
            {
                helper *= (sym.top() - '0');
            }
            else if(i == '/')
            {
                helper = (sym.top() - '0') / helper;
            }
            else if(i == '+')
            {
                helper += (sym.top() - '0');
            }
            else if(i == '-')
            {
                helper = (sym.top() - '0') - helper;
            }
            else if(i == '^')
            {
                helper = pow((sym.top() - '0'), helper);
            }
            sym.pop();
            sym.push(helper + '0');
        }
    }
    return sym.top() - '0';
}
