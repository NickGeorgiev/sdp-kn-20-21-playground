#define DOCTEST_CONFIG_IMPLEMENT

#include "Stack.h"
#include "../../../shared/specs/doctest.h"

TEST_CASE("Push/Top Test")
{   
    Stack<int> stack;
    stack.push(2);
    CHECK(stack.top() == 2);
    stack.push(3);
    CHECK(stack.top() == 3);
    stack.push(-1);
    CHECK(stack.top() == (size_t)-1);
}

TEST_CASE("Pop Test")
{   
    Stack<int> stack;
    stack.push(2);
    stack.push(3);
    stack.push(-1);
    stack.pop();
    CHECK(stack.top() == 3);
    stack.pop();
    stack.pop();
    stack.pop(); //Stack Empty!
}

TEST_CASE("Size Test")
{   
    Stack<int> stack;
    stack.push(2);
    stack.push(3);
    stack.push(-1);
    CHECK(stack.size() == 3);
    stack.pop();
    stack.pop();
    CHECK(stack.size() == 1);
    stack.pop();
    stack.pop(); //Stack Empty!
    CHECK(stack.size() == 0);
}

TEST_CASE("Empty Test")
{   
    Stack<int> stack;
    stack.push(2);
    stack.push(3);
    stack.push(-1);
    stack.pop();
    stack.pop();
    stack.pop();
    CHECK(stack.empty() == true);
}

TEST_CASE("Copy Test")
{   
    Stack<int> stack;
    stack.push(2);
    stack.push(1);
    stack.push(5);
    
    Stack<int> secondStack(stack);
    CHECK(secondStack.size() == 3);
    CHECK(secondStack.top() == 5);
    secondStack.pop();
    CHECK(secondStack.top() == 1);

    Stack<int> thirdStack = secondStack;
    CHECK(secondStack.size() == 2);
    CHECK(secondStack.top() == 1);
    secondStack.pop();
    CHECK(secondStack.top() == 2);
}


int main()
{
    doctest::Context().run(); 

    return 0;
}