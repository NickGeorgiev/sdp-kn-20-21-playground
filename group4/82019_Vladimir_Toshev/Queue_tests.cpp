#include "Queue.h"
#include "../../../sdp-kn-20-21-playground/shared/specs/specHelper.h"

TEST_CASE("Queue")
{
    SUBCASE("Empty")
    {
        SUBCASE("Has No Elements")
        {
            ///Given:
            Queue<int> test;

            ///When:

            ///Then:
            CHECK(test.empty());
        }

        SUBCASE("Has Elements")
        {
            ///Given:
            Queue<int> test;

            ///When:
            test.push(5);

            ///Then:
            CHECK(!test.empty());
        }
    }
    SUBCASE("Front")
    {
        SUBCASE("Has No Elements")
        {
            ///Given:
            Queue<int> test;

            ///When:

            ///Then:
            CHECK_THROWS_WITH_AS(test.front(), "No more elements", std::out_of_range);
        }

        SUBCASE("Has One Element")
        {
            ///Given:
            Queue<int> test;

            ///When:
            test.push(5);

            ///Then:
            CHECK(test.front() == 5);
        }

        SUBCASE("Has Multiple Elements")
        {
            ///Given:
            Queue<int> test;

            ///When:
            test.push(5);
            test.push(8);

            ///Then:
            CHECK(test.front() == 5);
        }
    }
    SUBCASE("Tail")
    {
        SUBCASE("Has No Elements")
        {
            ///Given:
            Queue<int> test;

            ///When:

            ///Then:
            CHECK_THROWS_WITH_AS(test.tail(), "No more elements", std::out_of_range);
        }

        SUBCASE("Has One Element")
        {
            ///Given:
            Queue<int> test;

            ///When:
            test.push(5);

            ///Then:
            CHECK(test.tail() == 5);
        }

        SUBCASE("Has Multiple Elements")
        {
            ///Given:
            Queue<int> test;

            ///When:
            test.push(5);
            test.push(8);

            ///Then:
            CHECK(test.tail() == 8);
        }
    }
    SUBCASE("Push")
    {

        SUBCASE("Has No Elements")
        {
            ///Given:
            Queue<int> test;

            ///When:
            test.push(5);

            ///Then:
            CHECK(!test.empty());
            CHECK(test.tail() == 5);
        }

        SUBCASE("Has One Element")
        {
            ///Given:
            Queue<int> test;

            ///When:
            test.push(5);

            ///Then:
            CHECK(test.front() == 5);

            ///When:
            test.push(8);

            ///Then:
            CHECK(test.front() == 5);
            CHECK(test.tail() == 8);
        }

        SUBCASE("Has Multiple Elements")
        {
            ///Given:
            Queue<int> test;

            ///When:
            test.push(5);
            test.push(8);

            ///Then:
            CHECK(test.front() == 5);
            CHECK(test.tail() == 8);

            ///When:
            test.push(9);

            ///Then:
            CHECK(test.front() == 5);
            CHECK(test.tail() == 9);

        }
    }
    SUBCASE("Pop")
    {
        SUBCASE("Has No Elements")
        {
            ///Given:
            Queue<int> test;

            ///When:

            ///Then:
            CHECK_THROWS_WITH_AS(test.pop(), "No more elements", std::out_of_range);
        }

        SUBCASE("Has One Element")
        {
            ///Given:
            Queue<int> test;

            ///When:
            test.push(5);

            ///Then:
            CHECK(test.tail() == 5);

            ///When:
            test.pop();

            ///Then:
            CHECK(test.empty());
            CHECK_THROWS_WITH_AS(test.tail(), "No more elements", std::out_of_range);
        }

        SUBCASE("Has Multiple Elements")
        {
            ///Given:
            Queue<int> test;

            ///When:
            test.push(5);
            test.push(8);
            test.push(9);

            ///Then:
            
            CHECK(test.front() == 5);
            CHECK(test.tail() == 9);
            CHECK(!test.empty());

            ///When:
            test.pop();

            ///Then:
            CHECK(!test.empty());
            CHECK(test.front() == 8);
            CHECK(test.tail() == 9);
        }
    }
}