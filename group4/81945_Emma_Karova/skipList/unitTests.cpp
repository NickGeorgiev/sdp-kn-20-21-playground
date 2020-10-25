#include "shared\specs\specHelper.h"
#include "skipList.h"

TEST_CASE("Locate function") {
    SkipList list;

    list.addElement(10);
    list.addElement(8);
    list.addElement(15);
    list.addElement(13);
    list.addElement(28);

    CHECK(list.locate(1) == nullptr);
    CHECK(list.locate(15)->data == 15);
    CHECK(list.locate(30)->data == 28);
    CHECK(list.locate(18)->data == 15);
}

TEST_CASE("Member function") {
    SkipList list;

    list.addElement(10);
    list.addElement(8);
    list.addElement(15);
    list.addElement(13);
    list.addElement(28);

    CHECK(!list.member(5));
    CHECK(list.member(15));
    CHECK(!list.member(18));
}

TEST_CASE("Adding element") {
    SkipList list;

    list.addElement(10);
    list.addElement(8);

    CHECK(list.locate(1) == nullptr);
    CHECK(list.locate(10)->data == 10);
    CHECK(list.locate(8)->data == 8);
}
