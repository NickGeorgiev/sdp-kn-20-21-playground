#include "skipList.h"
#include "../../../shared/specs/specHelper.h"

TEST_CASE("skip_tests")
{
    SUBCASE("push")
    {
        SkipList test_list;
        test_list.add_element(1);
        test_list.add_element(4);
        test_list.add_element(5);
        test_list.add_element(2);

        CHECK(test_list.get_size() == 4);
    }

    SUBCASE("elements")
    {
        SkipList test_list;
        test_list.add_element(1);
        test_list.add_element(4);
        test_list.add_element(5);
        test_list.add_element(2);

        CHECK(test_list.position(2)->next->data == 2);
        CHECK(test_list.position(2)->data == 1);
    }
}
