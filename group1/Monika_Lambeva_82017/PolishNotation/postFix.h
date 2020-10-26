#ifndef postFix_H
#define postFix_H
#include<string>
#include<stack>
#include<vector>

class PostFix
{
    private:
    std::string expresion;
    std::vector<char> num;
    std::stack<char> sym;
    public:
    PostFix(std::string expresion);
    //PostFix(std::vector<char> num);
    //std::vector<char> getNum()const;
    bool correctBracket();//ex.18.2
    bool advancedCorrect();//ex.18.3
    bool correct();
    void make();
    int calculating();
};

bool isDigit(char x);
bool isOperator(char x);
int priorityOperator(char x);

#endif
