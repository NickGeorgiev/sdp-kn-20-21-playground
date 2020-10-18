#define DOCTEST_CONFIG_IMPLEMENT
#include "Doctest/doctest.h"
#include "LList/LList.cpp"
#include<list>

TEST_CASE("Adding, finding, removing elements") {
    LList<int> skipList;
    SUBCASE("Finding in empty list") {
        CHECK(skipList.find(0) == -1);
    }

    for (int i = 0; i < 5; i++) {
        skipList.add(i);
        skipList.add(-i);
    }
    SUBCASE("Adding") {
        for (int i = -4; i <= 0; i++) {
            CHECK(skipList.find(i) == i + 4);
        }
        for (int i = 1; i < 5; i++) {
            CHECK(skipList.find(i) == i + 5);
        }
        CHECK(skipList.find(10) == -1);
        CHECK(skipList.find(-5) == -1);
    }
    SUBCASE("Removing") {
        skipList.pop();

        CHECK(skipList.find(4) == -1);
        CHECK(skipList.find(3) == 8);

        skipList.removeAll(0);
        CHECK(skipList.find(0) == -1);
        for (int i = -4; i <= -1; i++) {
            CHECK(skipList.find(i) == i + 4);
        }
        for (int i = 1; i <= 3; i++) {
            CHECK(skipList.find(i) == i + 3);
        }

        skipList.removeAll(-4);
        CHECK(skipList.find(-4) == -1);
        CHECK(skipList.find(-3) == 0);

        skipList.removeAll(3);
        CHECK(skipList.find(3) == -1);
        CHECK(skipList.find(2) == 4);
        

        skipList.deleteAt(0);
        CHECK(skipList.find(-3) == -1);
        CHECK(skipList.find(-2) == 0);

        skipList.deleteAt(3);
        CHECK(skipList.find(2) == -1);
        CHECK(skipList.find(1) == 2);

        skipList.deleteAt(1);
        CHECK(skipList.find(-2) == 0);
        CHECK(skipList.find(-1) == -1);
        CHECK(skipList.find(1) == 1);

        skipList.pop();
        skipList.pop();
        CHECK(skipList.empty());
    }
}



int main() {
    doctest::Context().run();
    return 0;
}