#include "doctest.h"
#include "SkipList.h"

TEST_CASE ("Constructors")
{
    SUBCASE ("Default")
    {
        SkipList slist;
        CHECK (slist.getSize() == 0);
    }

    SUBCASE ("Copy")
    {
        SkipList slist;
        slist.addElement(5);
        slist.addElement(12);
        slist.addElement(3);
        slist.addElement(17);

        SkipList slistCopy(slist);
        CHECK (slistCopy.getSize() == slist.getSize());
        CHECK (slistCopy.getNumSkipElements() == slist.getNumSkipElements());
    }
}

TEST_CASE ("Operator =")
{  
    SkipList slist;
    slist.addElement(5);
    slist.addElement(12);
    slist.addElement(3);
    slist.addElement(17);

    SkipList slistCopy;
    slistCopy = slist;

    CHECK (slistCopy.getSize() == slist.getSize());
    CHECK (slistCopy.getNumSkipElements() == slist.getNumSkipElements());
}

TEST_CASE ("Locate")
{
    SkipList slist;
    slist.addElement(5);
    slist.addElement(12);
    slist.addElement(3);
    slist.addElement(17);

    CHECK (slist.locate(12)->data == 12);
    CHECK (slist.locate(0) == nullptr);
    CHECK (slist.locate(20)->data == 17);
    CHECK (slist.locate(11)->data == 5);
}

TEST_CASE ("Optimize")
{
    SkipList slist;
    slist.addElement(5);
    slist.addElement(12);
    slist.addElement(3);

    CHECK (slist.getNumSkipElements() == 3);

    slist.addElement(17);

    CHECK (slist.getNumSkipElements() == 3);
}

TEST_CASE ("Add element")
{
    SkipList slist;
    slist.addElement(5);
    slist.addElement(12);
    slist.addElement(3);

    CHECK (slist.getSize() == 3);
}
