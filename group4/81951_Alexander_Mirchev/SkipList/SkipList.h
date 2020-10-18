#include <vector>
#include <math.h>
#include <iostream>

template <typename T>
class SkipList
{
private:
    struct SkipListNode
    {
        T data;
        SkipListNode *next;
        SkipListNode *skipNext;

        SkipListNode(const T &data, SkipListNode *next)
        {
            this->data = data;
            this->next = next;
            this->skipNext = nullptr;
        }
    };

    SkipListNode *start;
    int size;

public:
    SkipList()
    {
        start = nullptr;
        size = 0;
    }

    SkipList(const std::vector<T> &array)
    {
        start = nullptr;
        size = 0;

        for (int i = 0; i < array.size(); i++)
        {
            add(array[i]);
        }
    }

    ~SkipList()
    {
        SkipListNode *iterationNode = start;

        while (iterationNode)
        {
            SkipListNode *temp = iterationNode;
            iterationNode = iterationNode->next;
            delete temp;
        }
    }

    void add(const T &data)
    {
        if (start == nullptr)
        {
            start = new SkipListNode(data, nullptr);
        }

        else
        {
            SkipListNode *iteratedNode = start;

            while (iteratedNode->next && iteratedNode->next->data <= data)
            {
                iteratedNode = iteratedNode->next;
            }

            SkipListNode *iteratedNext = iteratedNode->next;
            iteratedNode->next = new SkipListNode(data, iteratedNext);
        }

        size++;

        if (floor(sqrt(size)) == sqrt(size))
        {
            setSkips();
        }
    }

    void setSkips()
    {

        const int skipStep = sqrt(size);

        if (size == 0)
            return;

        SkipListNode *iterationNode = start;
        SkipListNode *nodeToSkip = start;
        int skipStepRemainder = 0;

        while (iterationNode)
        {

            iterationNode->skipNext = nullptr;

            if (iterationNode != nodeToSkip && skipStepRemainder == 0)
            {
                nodeToSkip->skipNext = iterationNode;
                nodeToSkip = iterationNode;
            }

            if (++skipStepRemainder == skipStep)
            {
                skipStepRemainder = 0;
            }
            iterationNode = iterationNode->next;
        }
    }

    bool contains(const T &data)
    {
        return containsElement(data, start);
    }

    void printList()
    {

        SkipListNode *iterationNode = start;
        while (iterationNode)
        {
            std::cout << iterationNode->data << " ";
            iterationNode = iterationNode->next;
        }
    }

private:
    bool containsElement(const T &data, const SkipListNode *currentSkipListNode)
    {

        std::cout << currentSkipListNode->data << std::endl;

        if (data == currentSkipListNode->data)
        {
            return true;
        }

        if (currentSkipListNode->skipNext && currentSkipListNode->skipNext->data <= data)
        {
            return containsElement(data, currentSkipListNode->skipNext);
        }

        if (currentSkipListNode->next && currentSkipListNode->next->data <= data)
        {
            return containsElement(data, currentSkipListNode->next);
        }
        else
        {
            return false;
        }
    }
};
