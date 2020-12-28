#include<iostream>
#include<functional>

#include<string>
#include<stack>
#include<vector>

struct Operator {
    char sign;
    int precedence;
    std::function<int(int,int)> operation;
};

class ReversedPolishNotation {
    
    std::vector<Operator> operators;

    bool higherPrecedence(const char opA,const char opB) {
        int precedenceA = 0;
        int precedenceB = 0;
        for(Operator op : operators) {
            if(op.sign == opA) {
                precedenceA = op.precedence;
            }
            if(op.sign == opB) {
                precedenceB = op.precedence;
            }
        }
        return precedenceA > precedenceB;
    }

    bool isDigit(char c) {
        return (c >= '0' && c <= '9');
    }

    bool isOperator(char c) {
        for(Operator op : operators) {
            if(op.sign == c) {
                return true;
            }
        }
        return false;
    }

    int applyOperation(char c, char first, char second) {
        for(Operator op : operators) {
            if(op.sign == c) {
                return op.operation(first, second);
            }
        }
        return 0;
    }

    public:
    ReversedPolishNotation(const std::vector<Operator>& _operators) : operators{_operators} {}

    std::string parser(const std::string& input) {
        std::stack<char> stack;
        std::string output;

        for( const char c : input ) {
            if( isDigit(c) ) {
                output.push_back(c);

            } else if( c == '(' ) {
                stack.push(c);

            } else if( c == ')' ) {
                while ( stack.top() != '(' && !stack.empty() ) {
                    output.push_back(stack.top());
                    stack.pop();
                }
                stack.pop();
            }

            else if ( isOperator(c) ) {
                while( !stack.empty() && higherPrecedence( stack.top(), c )) {
                    output.push_back( stack.top() );
                    stack.pop();
                }
                stack.push( c );
            }            
        }

        while( !stack.empty() ) {
            output.push_back( stack.top() );
            stack.pop();
        }

        return output;
    }

    int solver(const std::string& notation) {
        std::stack<int> stack;
        for(const char c : notation) {
            if(isDigit(c)) {
                stack.push(c - '0');
            }
            else {
                char second;
                char first;

                if(!stack.empty()) {
                    second = stack.top(); stack.pop();
                }
                if(!stack.empty()) {
                    first = stack.top(); stack.pop();
                }

                stack.push(applyOperation(c, first, second));
            }
        }
        return stack.top();
    }
};

int main() {
    std::string normal = "1 + 5 * 2 * (8 / 4)";

    ReversedPolishNotation test({{'+', 1, [](int first,int second)->int{return first + second;}},
                                 {'-', 1, [](int first,int second)->int{return first - second;}},
                                 {'*', 2, [](int first,int second)->int{return first * second;}},
                                 {'/', 2, [](int first,int second)->int{return first / second;}},
                                 {'%', 2, [](int first,int second)->int{return first % second;}}});
    
    std::string rpn = test.parser(normal);
    int value = test.solver(rpn);

    std::cout << normal << std::endl;
    std::cout << rpn << std::endl;
    std::cout << "= " << value << std::endl;
}