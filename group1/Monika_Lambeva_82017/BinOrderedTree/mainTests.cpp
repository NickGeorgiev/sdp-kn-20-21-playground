#include"C:\Users\User\Documents\vs_code\sdp-kn-20-21-playground\shared\specs\specHelper.h"
#include "BOTree.h"
#include<fstream>

TEST_CASE("Added test(recursion)")
{
    BOTree<int> first;
    first.add(4);
    first.add(2);
    first.add(8);
    first.add(1);
    first.add(3);
    first.add(6);
    first.add(9);
    first.add(5);
    first.add(7);
    first.add(10);

    std::ofstream gvfile ("mytree_rec.gv");
    first.toGv(gvfile);
    gvfile.close();
}  

TEST_CASE("Added test(iter)")
{
    BOTree<int> first;
    first.add_iter(4);
    first.add_iter(2);
    first.add_iter(8);
    first.add_iter(1);
    first.add_iter(3);
    first.add_iter(6);
    first.add_iter(9);
    first.add_iter(5);
    first.add_iter(7);
    first.add_iter(10);

    std::ofstream gvfile ("mytree_iter.gv");
    first.toGv(gvfile);
    gvfile.close();
}  

TEST_CASE("Member")
{
    BOTree<int> first;
    first.add_iter(4);
    first.add_iter(2);
    first.add_iter(8);
    first.add_iter(1);
    first.add_iter(3);
    first.add_iter(6);
    first.add_iter(9);
    first.add_iter(5);
    first.add_iter(7);
    first.add_iter(10);

    CHECK(first.member(1) == true);
    CHECK(first.member(2) == true);
    CHECK(first.member(3) == true);
    CHECK(first.member(4) == true);
    CHECK(first.member(5) == true);
    CHECK(first.member(6) == true);
    CHECK(first.member(7) == true);
    CHECK(first.member(8) == true);
    CHECK(first.member(9) == true);
    CHECK(first.member(10) == true);
    CHECK(first.member(0) == false);
    CHECK(first.member(11) == false);
}  

TEST_CASE("Remove")
{
    BOTree<int> first;
    first.add_iter(4);
    first.add_iter(2);
    first.add_iter(8);
    first.add_iter(1);
    first.add_iter(3);
    first.add_iter(6);
    first.add_iter(9);
    first.add_iter(5);
    first.add_iter(7);
    first.add_iter(10);

    first.remove(1);
    std::ofstream gv_file_remove ("removeEl.gv");
    first.toGv(gv_file_remove);
    gv_file_remove.close();
    first.remove(8);
    std::ofstream gv_file_remove1 ("removeEl1.gv");
    first.toGv(gv_file_remove1);
    gv_file_remove1.close();
    first.remove(4);
    std::ofstream gv_file_remove2 ("removeEl2.gv");
    first.toGv(gv_file_remove2);
    gv_file_remove2.close();
}

TEST_CASE("Print")
{
    BOTree<int> first;
    first.add_iter(4);
    first.add_iter(2);
    first.add_iter(8);
    first.add_iter(1);
    first.add_iter(3);
    first.add_iter(6);
    first.add_iter(9);
    first.add_iter(5);
    first.add_iter(7);
    first.add_iter(10);

    CHECK(first.height() == 4);
    first.remove(6);
    CHECK(first.height() == 4);
    
    first.remove(5);
    first.remove(7);
    first.remove(10);
    CHECK(first.height() == 3); 
}

TEST_CASE("DFS RootLeftRight")
{
    BOTree<int> first;
    first.add_iter(4);
    first.add_iter(2);
    first.add_iter(8);
    first.add_iter(1);
    first.add_iter(3);
    first.add_iter(6);
    first.add_iter(9);
    first.add_iter(5);
    first.add_iter(7);
    first.add_iter(10);

    std::cout<<"dfsRootLeftRight: ";
    first.dfsRootLeftRight();
    std::cout<<"\ndfsRootRightLeft: ";
    first.dfsRootRightLeft();
    std::cout<<"\ndfsLeftRootRight: ";
    first.dfsLeftRootRight();
    std::cout<<"\ndfsRightRootLeft: ";
    first.dfsRightRootLeft();
    std::cout<<"\ndfsLeftRightRoot: ";
    first.dfsLeftRightRoot();
    std::cout<<"\ndfsRightLeftRoot: ";
    first.dfsRightLeftRoot();
    std::cout<<"\nbfs: ";
    first.bfs();
    std::cout<<'\n';
}