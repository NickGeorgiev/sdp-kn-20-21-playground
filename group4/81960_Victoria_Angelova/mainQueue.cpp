#include "Queue.cpp"
#include<iostream>

#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"


TEST_CASE("Push") {
    Queue<int> queue;

    CHECK(queue.getSize() == 0);

    queue.push(2);

    CHECK(queue.getSize() == 1);
    CHECK(queue.front() == 2);
    CHECK(queue.front() == queue.tail());

    queue.push(5);
    queue.push(6);

    CHECK(queue.getSize() == 3);
    CHECK(queue.front() == 2);
    CHECK(queue.tail() == 6);
}

TEST_CASE("Pop") {
    Queue<int> queue;

    try {
        queue.pop();
    }
    catch (const char* message) {
        CHECK(message == "The queue is empty. Nothing to pop.\n");
    }

    queue.push(11);
    queue.push(25);
    queue.push(36);

    CHECK(queue.getSize() == 3);
    CHECK(queue.front() == 11);
    
    queue.pop();

    CHECK(queue.getSize() == 2);
    CHECK(queue.front() == 25);

    CHECK(queue.pop() == 25);
    CHECK(queue.front() == 36);
}

TEST_CASE("Front") {
    Queue<int> queue;

    try {
        queue.front();
    }
    catch (const char* message) {
        CHECK(message == "The queue is empty.\n");
    }

    queue.push(1);
    queue.push(2);
    queue.push(3);

    CHECK(queue.front() == 1);

    queue.pop();

    CHECK(queue.front() == 2);
}

TEST_CASE("Tail") {
    Queue<int> queue;

    try {
        queue.tail();
    }
    catch (const char* message) {
        CHECK(message == "The queue is empty.\n");
    }

    queue.push(1);
    queue.push(2);
    queue.push(3);

    CHECK(queue.tail() == 3);

    queue.push(5);

    CHECK(queue.tail() == 5);
}


int main () {
    doctest::Context().run();
    
    return 0;
}
