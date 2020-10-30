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

PostFix::PostFix(std::string expresion):expresion(expresion){}

//ex.18.2
bool PostFix::correctBracket() 
{
    for(size_t i = 0; i < expresion.size(); i++)
    {
        if(expresion[i] == '(') sym.push(expresion[i]);
        else if(expresion[i] == ')')
        {
            if(sym.empty()) 
            {
                return false; 
            }
            sym.pop();
        }
    }
    if(sym.empty()) return true;
    return false;
}

//ex.18.3
bool PostFix::advancedCorrect()
{
    for(size_t i = 0; i < expresion.size(); i++)
    {
        if(expresion[i] == '(' || expresion[i] == '[' || expresion[i] == '{' ) sym.push(expresion[i]);
        else if(expresion[i] == ')')
        {
            if(sym.empty() || sym.top() != '(') return false;
            sym.pop();
        }
         else if(expresion[i] == ']')
        {
            if(sym.empty() || sym.top() != '[') return false;
            sym.pop();
        }
         else if(expresion[i] == '}')
        {
            if(sym.empty() || sym.top() != '{') return false;
            sym.pop();
        }
    }
    if(sym.empty()) return true;
    return false;
}

bool PostFix::correct()
{
    if(correctBracket())
    {
        for(size_t i = 0; i < expresion.size(); i++)
        {
            if(!(isDigit(expresion[i]) || isOperator(expresion[i]) || expresion[i] == '(' || expresion[i] == ')')) return false;
        }
        return true;
    }
    return false;
}

void PostFix::make()
{
    assert(correct());
    for(size_t i = 0; i < expresion.size(); i++)
    {
        if(isDigit(expresion[i])) num.push_back(expresion[i]);
        else if(expresion[i] == '(') sym.push(expresion[i]);
        else if(isOperator(expresion[i]))
        {
            while(!sym.empty() && priorityOperator(sym.top()) >= priorityOperator(expresion[i]))
            {
                num.push_back(sym.top());
                sym.pop();
            }
            sym.push(expresion[i]);
        }
        else if(expresion[i] == ')')
        {
            while(!sym.empty() && sym.top() != '(')
            {
                num.push_back(sym.top());
                
                sym.pop();
            }
            if(sym.top() == '(') sym.pop();
        }
    }
    while(!sym.empty())
    {
        num.push_back(sym.top());
        sym.pop();
    }
    for(size_t i=0;i<num.size();i++)
    {
        std::cout<<num[i];
    }
    std::cout<<"--->";    
}

int PostFix::calculating()
{
    make();
    for(size_t i = 0; i < num.size(); i++)
    {
        if(isDigit(num[i]))
        {
            sym.push(num[i]);
        }
        else if(isOperator(num[i]))
        {
            int helper = sym.top() - '0';
            sym.pop();
            if(num[i] == '*')
            {
                helper *= (sym.top() - '0');
            }
            else if(num[i] == '/')
            {
                helper = (sym.top() - '0') / helper;
            }
            else if(num[i] == '+')
            {
                helper += (sym.top() - '0');
            }
            else if(num[i] == '-')
            {
                helper = (sym.top() - '0') - helper;
            }
            else if(num[i] == '^')
            {
                helper = pow((sym.top() - '0'), helper);
            }
            sym.pop();
            sym.push(helper + '0');
        }
    }
    return sym.top() - '0';
}
