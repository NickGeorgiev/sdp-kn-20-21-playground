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

    static bool isDigit(char x);
    static bool isOperator(char x);
    static int priorityOperator(char x);
    static bool isOpeningBracket(char x);
    static bool isMixedOpeningBracket(char x);
    bool isMixedClosingBracket(char x);
    static bool isClosingBracket(char x);
    static char brackets(char x);

    public:
    PostFix(std::string expresion);
    bool correctBracket();//ex.18.2
    bool advancedCorrect();//ex.18.3
    bool correct();
    void make();
    int calculating();
};

#endif
