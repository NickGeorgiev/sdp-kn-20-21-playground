#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"

#include "SList.cpp"


TEST_CASE("Insertion of one element") {

    SList<int> test;
    test.push(1);
	CHECK(test.isMember(1));
}

TEST_CASE("Insertion of multiple elements") {
    SList<int> test;
    for(int i = 1 ; i <= 10 ; ++i) {
        test.push(i);
    }
    
    for(int i = 1 ; i <= 10 ; ++i) {
        CHECK(test.isMember(i));
    }

}

TEST_CASE("Removing of the only element") {
    SList<int> test;
    test.push(2);

    test.removeElement(2);

    CHECK(!test.isMember(2));
}

TEST_CASE("Removing of the last element") {
    SList<int> test;

    for(int i = 1 ; i <= 3 ; ++i) {
        test.push(i);
    }
    test.removeElement(3);

    CHECK(test.isMember(1));
    CHECK(test.isMember(2));
    CHECK(!test.isMember(3));

}

TEST_CASE("Removing of unexisting element") {
    SList<int> test;

    for(int i = 1 ; i <= 3 ; ++i) {
        test.push(i);
    }
    test.removeElement(4);

    CHECK(test.isMember(1));
    CHECK(test.isMember(2));
    CHECK(test.isMember(3));

}

TEST_CASE("Removing of a middle element") {
    SList<int> test;

    for(int i = 1 ; i <= 4 ; ++i) {
        test.push(i);
    }

    test.removeElement(2);

    
    CHECK(test.isMember(1));
    CHECK(!test.isMember(2));
    CHECK(test.isMember(3));
    CHECK(test.isMember(4));
}

TEST_CASE("Copy constructor") {
    SList<int> test;

    for(int i = 1 ; i <= 10 ; ++i) {
        test.push(i);
    }

    SList<int> copy(test);

    test.clear();
    
    for(int i = 1 ; i <= 10 ; ++i) {
        CHECK(copy.isMember(i));
    }

}

TEST_CASE("Empty and clear") {
    SList<int> list;
    CHECK(list.empty());

    list.push(1);
    list.push(2);

    list.clear();

    CHECK(list.empty());
}

int main() {
    doctest::Context().run();
}