#include"Stack.cpp"
#include"Queue.cpp"
#include<iostream>


int main () {
    Queue<int> q;

    for (int i = 0; i < 10; i++) {
        q.push(i);
    }
    for (int i = 0; i < 5; i++) {
        std::cout << q.top() << ' ';
        q.pop();
    }
    std::cout << '\n';

    for (int i = 10; i < 20; i++) {
        q.push(i);
    }
    while (!q.empty()) {
        std::cout << q.top() << ' ';
        q.pop();
    }

    try {
        std::cout << q.top() << ' ';
    }
    catch (std::out_of_range e) {
        std::cout << '\n' << e.what() << '\n';
    }

    return 0;
}