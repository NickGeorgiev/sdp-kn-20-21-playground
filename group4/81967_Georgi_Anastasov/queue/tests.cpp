#include "queue.h"
#include "../../../shared/specs/specHelper.h"

TEST_CASE("queue_tests")
{
    SUBCASE("push/tail tests")
    {
        Queue test_queue;

        test_queue.push(10);
        CHECK(test_queue.tail() == 10);

        test_queue.push(-10);
        test_queue.push(7);
        test_queue.pop();
        CHECK(test_queue.tail() == 7);
    }

    SUBCASE("pop/front tests")
    {
        Queue test_queue;

        test_queue.push(100);
        CHECK(test_queue.front() == 100);

        test_queue.push(55);
        test_queue.pop();

        CHECK(test_queue.front() == 55);
    }
}
