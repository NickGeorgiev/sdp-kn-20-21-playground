#include <iostream>
#include <string>
#include <stack>
#include <vector>

int main()
{

    std::string input;

    std::cout<< "Enter an expression:";

    getline(std::cin, input);


    std::stack<char> operation_stack;

    std::vector<char> result;

    std::string lookUpTable = "-+*/()";

    for (size_t i = 0; i < input.size(); i++)
    {
        char symbol = input[i];
        if(symbol == ' ')
        {
            continue;
        }
        size_t found = lookUpTable.find(symbol);
        if(found == std::string::npos)
        {
            result.insert(result.end(), symbol);
        }else{
            if(symbol == ')'){
                    char curr = operation_stack.top();
                    operation_stack.pop();
                    while (curr != '('){
                        result.insert(result.end(), curr);
                        curr = operation_stack.top();
                        operation_stack.pop();
                    }
                }else{
                    if(symbol == '+' ){
                        while (!operation_stack.empty() && (operation_stack.top() == '-' || operation_stack.top() == '+')){
                            result.insert(result.end(), operation_stack.top());
                            operation_stack.pop();
                        }
                        operation_stack.push(symbol);
                    }else if(symbol == '-'){
                        while (!operation_stack.empty() && (operation_stack.top() == '+' || operation_stack.top() == '-')){
                            result.insert(result.end() ,operation_stack.top());
                            operation_stack.pop();
                        }
                        operation_stack.push(symbol);
                    }else if(symbol == '/'){
                        while (!operation_stack.empty() && (operation_stack.top() == '*' || operation_stack.top() == '/')){
                            result.insert(result.end() ,operation_stack.top());
                            operation_stack.pop();
                        }
                        operation_stack.push(symbol);
                    }else if(symbol == '*'){
                        while (!operation_stack.empty() && (operation_stack.top() == '/' || operation_stack.top() == '*')){
                            result.insert(result.end() ,operation_stack.top());
                            operation_stack.pop();
                        }
                        operation_stack.push(symbol);
                    }else{
                        operation_stack.push(symbol);
                    }
                }
        }
    }
    
    while (!operation_stack.empty()){
            result.insert(result.end() ,operation_stack.top());
            operation_stack.pop();
        }

    ;

    for (std::vector<char>::iterator it = result.begin(); it != result.end(); it++)
    {
        std::cout<< *it << " ";
    }
    

    return 0;
}