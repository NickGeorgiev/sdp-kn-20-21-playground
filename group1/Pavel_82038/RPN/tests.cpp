#define DOCTEST_CONFIG_IMPLEMENT

#include "RPN.cpp"

TEST_CASE("Conversion test")
{
    CHECK(convertExpression("2^3") == "23^");
    CHECK(convertExpression("5+7+1+2") == "57+1+2+");
    CHECK(convertExpression("(5+(7+(1+2)))") == "5712+++");
    CHECK(convertExpression("((1+2)*3/(1+2))") == "12+3*12+/");
}

TEST_CASE("Calculation test")
{
    CHECK(calculateRPN(convertExpression("2^3")) == 8);
    CHECK(calculateRPN(convertExpression("5+7+1+2")) == 15);
    CHECK(calculateRPN(convertExpression("(5+(7+(1+2)))")) == 15);
    CHECK(calculateRPN(convertExpression("((1+2)*3/(1+2))")) == 3);
}

int main()
{
    doctest::Context().run(); 

    return 0;
}