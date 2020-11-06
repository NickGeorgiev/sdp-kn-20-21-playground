#include"shared/specs/specHelper.h"
#include "postFix.h"


TEST_CASE("Correction test")
{
    PostFix p("{x+(y+[1+2])}");
    PostFix s("{(x+y)*3]+(x+(1+2}");
    PostFix p1("(x+(y+(1+2)))");
    PostFix s1("((x+y)*3+(x+(1+2)");
    PostFix p2("(6*(8/(1-2)))");
    CHECK(p.advancedCorrect() == 1); 
    CHECK(s.advancedCorrect() == 0);
    CHECK(p1.correctBracket() == 1); 
    CHECK(s1.correctBracket() == 0);
    CHECK(p.correct() == 0);
    CHECK(p2.correct() == 1);
}  

TEST_CASE("Calculating test")
{
    PostFix p("(5+(7+(1+2)))");
    PostFix s("((1+2)*3/(1+2))");
    PostFix f("1^2-1*4");
    CHECK(p.calculating() == 15);
    CHECK(s.calculating() == 3);
    CHECK(f.calculating() == -3);
}  
