#include "skiplist.h"
#include <iostream>
#include <cmath>

template <class T>
void SkipList<T>::copyList(const SkipList<T> &other)
{
    this->start = this->end = nullptr;
    Node<T> *otherCurrent = other.start;
    while (otherCurrent)
    {
        this->toEnd(otherCurrent->value);
        otherCurrent = otherCurrent->next;
    }
}
template <class T>
void SkipList<T>::redefineSkipper() ///Redefines the elements we skip from and to
{
    const size_t skipValue = sqrt(this->size()) + 1; /// If the indexes of our elemets are 0 1 2 3 4 5 6 7 8, then the value of sqrt(size) is 3, hence we want to skip from 0->4 and from 4->8, thus making the value of the module sqrt(size) + 1
    size_t counter = 1;

    Node<T> *curr = start->next;
    Node<T> *toSkipFrom = start;

    while (curr)
    {
        curr->skip = nullptr;

        if (counter % skipValue == 0 || !curr->next)
        {
            toSkipFrom->skip = curr;
            toSkipFrom = curr;
        }

        curr = curr->next;
        ++counter;
    }
}

template <class T>
void SkipList<T>::destroyList()
{
    while (start)
    {
        Node<T> *previous = start;
        start = start->next;
        delete previous;
    }

    start = end = nullptr;
}

template <class T>
SkipList<T>::SkipList()
{
    start = nullptr;
    end = nullptr;
};
template <class T>
SkipList<T>::SkipList(const SkipList &other)
{
    copyList(other);
}

template <class T>
SkipList<T>::~SkipList()
{
    destroyList();
};
template <class T>
SkipList<T> &SkipList<T>::operator=(const SkipList &other)
{
    if (this != &other)
    {
        this->destroyList();
        this->copyList(other);
    }

    return *this;
}

template <class T>
size_t SkipList<T>::size() const
{
    size_t skipListSize = 0;

    Node<T> *curr = start;

    while (curr)
    {
        ++skipListSize;
        curr = curr->next;
    }

    return skipListSize;
}

template <class T>
void SkipList<T>::toStart(const T &value)
{
    start = new Node<T>(value, start, nullptr);
    if (!start->next)
    {
        end = start; ///If there is only 1 element, we do not need to even try to create skips
    }
    else
    {
        redefineSkipper();
    }
}

template <class T>
void SkipList<T>::toEnd(const T &value)
{
    if (!start)
    {
        start = end = new Node<T>(value, nullptr, nullptr); ///If there is only 1 element, we do not need to even try to create skips
    }
    else
    {
        end->next = new Node<T>(value, nullptr, nullptr);
        end = end->next;
        redefineSkipper();
    }
}

template <class T>
Node<T> *SkipList<T>::member(const T &key) const ///Returns the member with the max value <= of the one we are searching for, aka the member after the new Value should be added
{
    if (start->value > key) ///If start has a higher value, we return nullptr, as the element with value key will be added before start
    {
        return nullptr;
    }
    else if (end->value < key) ///If end has a lower value, then we return end, as the element with value key will be added after end
    {
        return end;
    }

    Node<T> *curr = start;

    while (curr->skip->value <= key && curr) ///We skip most of the elements, as the list is already sorted when we add a new one
    {
        curr = curr->skip;
    }

    if (curr->value != key) ///If the value we have skipped to is not the one we are looking for, then we start looking for the desired element inbetween the skips
    {
        while (curr->next->value <= key && curr) ///From the previous cycle we know that at the beginning the curr elements has a value <= the one we are looking for.
                                                 ///So we start switching to the next one until:
                                                 ///1)The next one is the value we are looking for
                                                 ///2)The next one is of a higher value, then the value of curr is the max value <= of the one we are looking for
        {
            curr = curr->next;
        }
    }

    return curr; ///We return the element, after which key should be added
}

template <class T>
void SkipList<T>::addElement(const T &elementToAdd)
{
    Node<T> *predecessor = member(elementToAdd);

    if (!predecessor)
    {
        toStart(elementToAdd);
    }
    else if (predecessor == this->end)
    {
        toEnd(elementToAdd);
    }
    else
    {
        predecessor->next = new Node<T>(elementToAdd, predecessor->next, nullptr);

        redefineSkipper();
    }
}

template <class T>
void SkipList<T>::printSkips() const
{
    Node<T> *curr = start;

    while (curr)
    {
        std::cout << curr->value << " ";

        curr = curr->skip;
    }
}

template <class T>
void SkipList<T>::print() const
{
    Node<T> *curr = start;

    while (curr)
    {
        std::cout << curr->value << " ";
        curr = curr->next;
    }
}

int main()
{
    SkipList<int> test;

    test.toStart(1); ///skip one
    test.toEnd(2);   ///skipped
    test.toEnd(3);   ///skipped
    test.toEnd(4);   ///skipped
    test.toEnd(5);   /// 1->5, skip two
    test.toEnd(7);   ///skipped
    test.toEnd(8);   ///skipped
    test.toEnd(9);   ///skipped
    test.toEnd(10);  ///5->10, skip three
    test.toEnd(11);  ///10->11

    std::cout << std::endl
              << "Skips: ";
    test.printSkips();
    std::cout << std::endl
              << "All elements: ";
    test.print();
    std::cout << std::endl;

    Node<int> *testNode = test.member(0);
    std::cout << std::endl
              << "Is the value of member(0) nullptr: " << testNode << std::endl;
    testNode = test.member(6);
    std::cout << std::endl
              << "The value of member before 6: " << testNode->value << std::endl;
    testNode = test.member(15);
    std::cout << std::endl
              << "Is the value of member(15) the end of the list: " << testNode->value << std::endl;

    test.addElement(6); ///Let's see if we can add an elment to the middle

    std::cout << std::endl
              << "Skips: ";
    test.printSkips();
    std::cout << std::endl
              << "All elements: ";
    test.print();
    std::cout << std::endl;

    test.addElement(0);  ///Let's see if we can add an element to the front
    test.addElement(12); ///Let's see if we can add an element to the back
    std::cout << std::endl
              << "Skips: ";
    test.printSkips();
    std::cout << std::endl
              << "All elements: ";
    test.print();
    std::cout << std::endl;

    test.addElement(13); ///Let's see if after we add multiple element the skips are changed correctly
    test.addElement(14);
    test.addElement(13); ///See if we can add repetitive elements without issue
    test.addElement(13);
    test.addElement(13);

    std::cout << std::endl
              << "Skips: ";
    test.printSkips();
    std::cout << std::endl
              << "All elements: ";
    test.print();
    std::cout << std::endl;

    std::cout << std::endl
              << "Size: " << test.size()
              << std::endl;

    SkipList<int> test2(test);
    SkipList<int> test3 = test;

    std::cout << std::endl
              << "Copy constructor test!"
              << std::endl
              << "Skips: ";
    test2.printSkips();
    std::cout << std::endl
              << "All elements: ";
    test2.print();
    std::cout << std::endl;

    std::cout << std::endl
              << "Operator = test!"
              << std::endl
              << "Skips: ";
    test3.printSkips();
    std::cout << std::endl
              << "All elements: ";
    test3.print();
    std::cout << std::endl;
}
