#include "skiplist.h"
#include "../../../shared/specs/specHelper.h"

TEST_CASE("SkipList")
{
    SUBCASE("Construction")
    {
        SUBCASE("Default construction")
        {
            //Given:
            SkipList<int> testSkipList;

            //Then:
            CHECK(!testSkipList.member(5));
            CHECK(!testSkipList.locate(5));
        }

        SUBCASE("Copy constructor")
        {
            //Given:
            SkipList<int> testSkipListCopyFirst;

            //When:
            testSkipListCopyFirst.toEnd(1);
            testSkipListCopyFirst.toEnd(2);

            SkipList<int> testSkipListCopySecond(testSkipListCopyFirst);

            //Then:
            CHECK(testSkipListCopySecond.member(1));
            CHECK(testSkipListCopySecond.member(2));
            CHECK(!testSkipListCopySecond.member(3));
        }
    }

    SUBCASE("Operator =")
    {
        //Given:
        SkipList<int> testSkipListOperatorFirst;
        SkipList<int> testSkipListOperatorSecond;

        //When:
        testSkipListOperatorFirst.toEnd(1);
        testSkipListOperatorFirst.toEnd(2);

        testSkipListOperatorSecond = testSkipListOperatorFirst;

        //Then:
        CHECK(testSkipListOperatorSecond.member(1));
        CHECK(testSkipListOperatorSecond.member(2));
        CHECK(!testSkipListOperatorSecond.member(3));
    }

    SUBCASE("Functions")
    {
        SUBCASE("Size")
        {
            SUBCASE("Size when empty")
            {
                //Given:
                SkipList<int> testSkipListEmpty;

                //When:

                //Then:
                CHECK(testSkipListEmpty.getSize() == 0);
            }

            SUBCASE("Size when not empty")
            {
                //Given:
                SkipList<int> testSkipListNotEmpty;

                //When:
                testSkipListNotEmpty.toEnd(1);
                testSkipListNotEmpty.toEnd(2);

                //Then:
                CHECK(testSkipListNotEmpty.getSize() == 2);
            }
        }

        SUBCASE("Member")
        {
            SUBCASE("Member when empty")
            {
                //Given:
                SkipList<int> testSkipListMember;

                //When:

                //Then:

                CHECK(!testSkipListMember.member(1));
            }

            SUBCASE("Member when not empty")
            {
                //Given:
                SkipList<int> testSkipListFirst;

                //When:
                testSkipListFirst.toEnd(1);
                testSkipListFirst.toEnd(2);

                //Then:
                CHECK(testSkipListFirst.member(1));
                CHECK(!testSkipListFirst.member(3));
            }
        }

        SUBCASE("toStart")
        {
            SUBCASE("toStart when empty")
            {
                //Given:
                SkipList<int> testSkipListToStart;

                //Then:
                CHECK(!testSkipListToStart.member(1));
                CHECK(testSkipListToStart.getSize() == 0);

                //When:
                testSkipListToStart.toStart(1);

                //Then:
                CHECK(testSkipListToStart.member(1));
                CHECK(testSkipListToStart.getSize() == 1);
            }
            SUBCASE("toStart when not empty")
            {
                //Given:
                SkipList<int> testSkipListToStart;

                //When:
                testSkipListToStart.toStart(1);

                //Then:
                CHECK(testSkipListToStart.member(1));
                CHECK(!testSkipListToStart.member(2));
                CHECK(testSkipListToStart.getSize() == 1);

                //When:
                testSkipListToStart.toStart(2);
                //Then:
                CHECK(testSkipListToStart.member(2));
                CHECK(testSkipListToStart.getSize() == 2);
            }
        }

        SUBCASE("toEnd")
        {
            SUBCASE("toEnd when empty")
            {
                //Given:
                SkipList<int> testSkipListToStart;

                //Then:
                CHECK(!testSkipListToStart.member(1));
                CHECK(testSkipListToStart.getSize() == 0);
                //When:
                testSkipListToStart.toEnd(1);

                //Then:
                CHECK(testSkipListToStart.member(1));
                CHECK(testSkipListToStart.getSize() == 1);
            }
            SUBCASE("toStart when not empty")
            {
                //Given:
                SkipList<int> testSkipListToStart;

                //When:
                testSkipListToStart.toEnd(1);

                //Then:
                CHECK(testSkipListToStart.member(1));
                CHECK(!testSkipListToStart.member(2));
                CHECK(testSkipListToStart.getSize() == 1);

                //When:
                testSkipListToStart.toEnd(2);
                //Then:
                CHECK(testSkipListToStart.member(2));
                CHECK(testSkipListToStart.getSize() == 2);
            }
        }

        SUBCASE("Locate")
        {

            SUBCASE("Locate when empty")
            {
                //Given:
                SkipList<int> testSkipListLocateEmpty;

                //When:

                //Then
                CHECK(testSkipListLocateEmpty.locate(5) == nullptr);
            }

            SUBCASE("Locate when not empty")
            {
                SUBCASE("Locate when not empty, key value < first element")
                {
                    //Given:
                    SkipList<int> testSkipLocateNotEmpty;

                    //When:
                    testSkipLocateNotEmpty.toEnd(1);
                    testSkipLocateNotEmpty.toEnd(2);
                    testSkipLocateNotEmpty.toEnd(3);

                    //Then:
                    CHECK(testSkipLocateNotEmpty.locate(0) == nullptr);
                }

                SUBCASE("Locate when not empty, key value = first element")
                {
                    //Given:
                    SkipList<int> testSkipLocateNotEmpty;

                    //When:
                    testSkipLocateNotEmpty.toEnd(1);
                    testSkipLocateNotEmpty.toEnd(2);
                    testSkipLocateNotEmpty.toEnd(3);

                    //Then:
                    CHECK(testSkipLocateNotEmpty.locate(1)->value == 1);
                }

                SUBCASE("Locate when not empty, key value > last element")
                {
                    //Given:
                    SkipList<int> testSkipLocateNotEmpty;

                    //When:
                    testSkipLocateNotEmpty.toEnd(1);
                    testSkipLocateNotEmpty.toEnd(2);
                    testSkipLocateNotEmpty.toEnd(3);

                    //Then:
                    CHECK(testSkipLocateNotEmpty.locate(5)->value == 3);
                }

                SUBCASE("Locate when not empty, key value = last element")
                {
                    //Given:
                    SkipList<int> testSkipLocateNotEmpty;

                    //When:
                    testSkipLocateNotEmpty.toEnd(1);
                    testSkipLocateNotEmpty.toEnd(2);
                    testSkipLocateNotEmpty.toEnd(3);

                    //Then:
                    CHECK(testSkipLocateNotEmpty.locate(3)->value == 3);
                }

                SUBCASE("Locate when not empty, key value not withint the list")
                {
                    //Given:
                    SkipList<int> testSkipLocateNotEmpty;

                    //When:
                    testSkipLocateNotEmpty.toEnd(1);
                    testSkipLocateNotEmpty.toEnd(2);
                    testSkipLocateNotEmpty.toEnd(4);

                    //Then:
                    CHECK(testSkipLocateNotEmpty.locate(3)->value == 2);
                }

                SUBCASE("Locate when not empty, key value within the list")
                {
                    //Given:
                    SkipList<int> testSkipLocateNotEmpty;

                    //When:
                    testSkipLocateNotEmpty.toEnd(1);
                    testSkipLocateNotEmpty.toEnd(2);
                    testSkipLocateNotEmpty.toEnd(3);

                    //Then:
                    CHECK(testSkipLocateNotEmpty.locate(2)->value == 2);
                }
            }
        }

        SUBCASE("Add Element")
        {
            SUBCASE("Add element when empty")
            {
                //Given:
                SkipList<int> testSkipAddElementElmpty;

                //Then:
                CHECK(!testSkipAddElementElmpty.member(1));
                CHECK(testSkipAddElementElmpty.getSize() == 0);
                //When:
                testSkipAddElementElmpty.addElement(1);

                //Then:
                CHECK(testSkipAddElementElmpty.member(1));
                CHECK(testSkipAddElementElmpty.getSize() == 1);
            }
            SUBCASE("Add element when not empty")
            {
                SUBCASE("Add element when not empty, key value < first element")
                {
                    //Given:
                    SkipList<int> testSkipAddElementElmpty;

                    //When:
                    testSkipAddElementElmpty.addElement(1);

                    //Then:
                    CHECK(testSkipAddElementElmpty.member(1));
                    CHECK(testSkipAddElementElmpty.getSize() == 1);

                    //When:
                    testSkipAddElementElmpty.addElement(0);

                    //Then:
                    CHECK(testSkipAddElementElmpty.member(0));
                    CHECK(testSkipAddElementElmpty.getSize() == 2);
                }

                SUBCASE("Add element when not empty, key value not withint the list")
                {
                    //Given:
                    SkipList<int> testSkipLocateNotEmpty;

                    //When:
                    testSkipLocateNotEmpty.addElement(1);
                    testSkipLocateNotEmpty.addElement(2);
                    testSkipLocateNotEmpty.addElement(4);

                    //Then:
                    CHECK(!testSkipLocateNotEmpty.member(3));
                    CHECK(testSkipLocateNotEmpty.getSize() == 3);

                    //When:
                    testSkipLocateNotEmpty.addElement(3);

                    //Then:
                    CHECK(testSkipLocateNotEmpty.member(3));
                    CHECK(testSkipLocateNotEmpty.getSize() == 4);
                }

                SUBCASE("Add element when not empty, key value within the list")
                {
                    //Given:
                    SkipList<int> testSkipLocateNotEmpty;

                    //When:
                    testSkipLocateNotEmpty.addElement(1);
                    testSkipLocateNotEmpty.addElement(2);
                    testSkipLocateNotEmpty.addElement(4);

                    //Then:
                    CHECK(testSkipLocateNotEmpty.member(2));
                    CHECK(testSkipLocateNotEmpty.getSize() == 3);

                    //When:
                    testSkipLocateNotEmpty.addElement(2);

                    //Then:
                    CHECK(testSkipLocateNotEmpty.member(2));
                    CHECK(testSkipLocateNotEmpty.getSize() == 4);
                }

                SUBCASE("Add element when not empty, key value > last element")
                {
                    //Given:
                    SkipList<int> testSkipLocateNotEmpty;

                    //When:
                    testSkipLocateNotEmpty.addElement(1);
                    testSkipLocateNotEmpty.addElement(2);
                    testSkipLocateNotEmpty.addElement(3);

                    //Then:
                    CHECK(!testSkipLocateNotEmpty.member(4));
                    CHECK(testSkipLocateNotEmpty.getSize() == 3);

                    //When:
                    testSkipLocateNotEmpty.addElement(4);

                    //Then:
                    CHECK(testSkipLocateNotEmpty.member(4));
                    CHECK(testSkipLocateNotEmpty.getSize() == 4);
                }
            }
        }
    }
}
