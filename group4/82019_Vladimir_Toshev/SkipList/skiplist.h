#ifndef _SKIPLIST_HH
#define _SKIPLIST_HH
#include <iostream>
#include <cmath>

template <class T>
class SkipList
{
private:
    struct Node
    {
        T value;
        Node *next;
        Node *skip;

        Node(const T &_value, Node *_next, Node *_skip) : value{_value}, next{_next}, skip{_skip} {}
    };

    Node *start;
    Node *end;
    size_t size;

    void copyList(const SkipList &other)
    {
        this->start = this->end = nullptr;
        Node *otherCurrent = other.start;

        this->size = 0;
        while (otherCurrent)
        {
            this->toEnd(otherCurrent->value);
            otherCurrent = otherCurrent->next;
        }
    }

    void redefineSkipper() ///Redefines the elements we skip from and to
    {
        const size_t skipValue = sqrt(this->size) + 1; /// If the indexes of our elemets are 0 1 2 3 4 5 6 7 8, then the value of sqrt(size) is 3, hence we want to skip from 0->4 and from 4->8, thus making the value of the module sqrt(size) + 1
        size_t counter = 1;

        Node *curr = start->next;
        Node *toSkipFrom = start;

        while (curr)
        {
            curr->skip = nullptr;

            if (counter % skipValue == 0 || curr == end)
            {
                toSkipFrom->skip = curr;
                toSkipFrom = curr;
            }

            curr = curr->next;
            ++counter;
        }
    }

    void destroyList()
    {
        while (start)
        {
            Node *previous = start;
            start = start->next;
            delete previous;
        }

        start = end = nullptr;
        size = 0;
    }

public:
    SkipList() : start{nullptr}, end{nullptr}, size{0} {};

    SkipList(const SkipList &other)
    {
        copyList(other);
    }

    ~SkipList()
    {
        destroyList();
    };

    SkipList<T> &operator=(const SkipList &other)
    {
        if (this != &other)
        {
            this->destroyList();
            this->copyList(other);
        }

        return *this;
    }

    size_t getSize() const
    {
        return this->size;
    }

    void toStart(const T &value)
    {
        size++;

        start = new Node(value, start, nullptr);
        if (!start->next)
        {
            end = start; ///If there is only 1 element, we do not need to even try to create skips
        }
        else
        {
            redefineSkipper();
        }
    }

    void toEnd(const T &value)
    {
        size++;

        if (!start)
        {
            start = end = new Node(value, nullptr, nullptr); ///If there is only 1 element, we do not need to even try to create skips
        }
        else
        {
            end->next = new Node(value, nullptr, nullptr);
            end = end->next;
            redefineSkipper();
        }
    }

    Node *locate(const T &key) const ///Returns the locate with the max value <= of the one we are searching for, aka the locate after the new Value should be added
    {
        if (!start)
        {
            return nullptr;
        }
        else if (start->value == key)
        {
            return start;
        }
        else if (start->value > key) ///If start has a higher value, we return nullptr, as the element with value key will be added before start
        {
            return nullptr;
        }
        else if (end->value <= key) ///If end has a lower value, then we return end, as the element with value key will be added after end
        {
            return end;
        }

        Node *curr = start; ///After the prvious ifs we always have a start node = nullptr

        while (curr->skip->value <= key && curr) ///We skip most of the elements, as the list is already sorted when we add a new one
        {
            curr = curr->skip;
        }

        if (curr->value = key) ///If the value we have skipped to is not the one we are looking for, then we start looking for the desired element inbetween the skips
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

    bool member(const T &key) const
    {
        if (!this->size)
        {
            return false;
        }

        Node *location = this->locate(key);
        return location->value == key;
    }

    void addElement(const T &elementToAdd) ///Adds element
    {
        Node *predecessor = locate(elementToAdd);

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
            predecessor->next = new Node(elementToAdd, predecessor->next, nullptr);
            ++size;
        }

        redefineSkipper();
    }

    void print() const ///Prints all elements
    {
        Node *curr = start;

        while (curr)
        {
            std::cout << curr->value << " ";
            curr = curr->next;
        }
    }
};

#endif
