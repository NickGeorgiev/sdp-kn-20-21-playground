//#include "specs.h"
#include "postFix.h"
#include<iostream>


//TEST_CASE("testing the Balance function")
//{
// PostFix p("{x+(y+[1+2])}");
// PostFix s("{(x+y)*3]+(x+(1+2}");
// PostFix p1("(x+(y+(1+2)))");
// PostFix s1("((x+y)*3+(x+(1+2)");
//    CHECK(p.advancedBalance() == 1); 
//    CHECK(s.advancedBalance() == 0);
//    CHECK(p1.balance() == 1); 
//    CHECK(s1.balance() == 0);
//}  
//
//TEST_CASE("testing the make function")
//{
//    PostFix p("(x+(y+(1+2)))");
//    PostFix s("((x+y)*3+(x+(1+2)");
//       p.make(); 
//       s.make();
//    PostFix p1("xy+12++");
//    CHECK(p.getNum() == p1.getNum());
//    CHECK(p.getNum().empty());
//}  

int main()
{   
    //doctest::Context().run();    
    PostFix p("(5+(7+(1+2)))");
    PostFix s("((1+2)*3/(1+2))");
    PostFix s1("1^2-1*4");
 
    std::cout<< p.calculating()<<std::endl;
    std::cout<< s.calculating()<<std::endl;
    std::cout<< s1.calculating()<<std::endl;

    return 0;
}
