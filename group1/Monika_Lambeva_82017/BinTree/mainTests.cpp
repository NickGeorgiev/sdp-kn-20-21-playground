#include"shared/specs/specHelper.h"
#include "BinTree.h"

TEST_CASE("Added test")
{
    BinTree<int> first;
    first.add(1,"");
    first.add(2,"R");
    first.add(3,"L");
    first.add(4,"LL");
    first.add(5,"LLR");
    first.add(6,"LLL");
    first.add(7,"LLLR");

    CHECK(first.get("") == 1);
    CHECK(first.get("R") == 2);
    CHECK(first.get("L") == 3);
    CHECK(first.get("LL") == 4);
    CHECK(first.get("LLR") == 5);
    CHECK(first.get("LLL") == 6);
    CHECK(first.get("LLLR") == 7);

    std::ofstream gvfile ("mytree.gv");
    first.toGv(gvfile);
}  

TEST_CASE("Counter Test")
{
    BinTree<int> first;
    first.add(1,"");
    first.add(2,"R");
    first.add(3,"L");
    first.add(4,"LL");
    first.add(5,"LLR");
    first.add(6,"LLL");     

    CHECK(first.count() == 6);
}

TEST_CASE("CountEvens Test")
{
    BinTree<int> first;
    first.add(1,"");
    first.add(2,"R");
    first.add(3,"L");
    first.add(4,"LL");
    first.add(5,"LLR");
    first.add(6,"LLL");     

    CHECK(first.countEvens() == 3);
}

TEST_CASE("SearchCount Test")
{
    BinTree<int> first;
    first.add(1,"");
    first.add(2,"R");
    first.add(3,"L");
    first.add(4,"LL");
    first.add(5,"LLR");
    first.add(6,"LLL");     
    first.add(7,"LLLR");

    CHECK(first.searchCount([](const int& x){return x % 2 == 0;}) == 3);
    CHECK(first.searchCount([](const int& x){return x % 2 == 1;}) == 4);
}

TEST_CASE("Height Test")
{
    BinTree<int> first;
    first.add(1,"");
    first.add(2,"R");
    first.add(3,"L");
    first.add(4,"LL");
    first.add(5,"LLR");
    first.add(6,"LLL");     
    first.add(7,"LLLR");

    CHECK(first.height() == 5);
}
