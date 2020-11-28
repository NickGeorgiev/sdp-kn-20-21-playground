#include "skipList.h"
int main()
{
    SkipList *list = new SkipList();
    int member = 5;

    list->addMember(member);

    member = 4;
    list->addMember(member);

    member = 3;
    list->addMember(member);

    member = 12;
    list->addMember(member);

    member = 1;
    list->addMember(member);

    member = 6;
    list->addMember(member);

    member = 19;
    list->addMember(member);
    member = 2;
    list->addMember(member);

    member = 3;
    list->addMember(member);

    list->printList();
    list->printSkips();

     SkipList *list2 = new SkipList(*list);
list2->printList();
list2->printSkips();
    delete list2;
    delete list;
    return 0;
}