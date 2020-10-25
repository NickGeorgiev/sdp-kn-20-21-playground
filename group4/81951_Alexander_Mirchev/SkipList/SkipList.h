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

        SkipListNode(const T &data, SkipListNode *next, SkipListNode *skipNext)
        {
            this->data = data;
            this->next = next;
            this->skipNext = skipNext;
        }
    };

    SkipListNode *start;
    SkipListNode *end;
    int size;

public:
    SkipList()
    {
        start = nullptr;
        end = nullptr;
        size = 0;
    }

    SkipList(const SkipList &other) : SkipList()
    {
        if (other.size == 0)
        {
            return;
        }

        this->size = other.size;

        SkipListNode *otherIterationNode = other.start;

        SkipListNode *thisNodeToSkip = nullptr;

        int skipStep = sqrt(this->size);
        int skipStepRemainder = 0;

        while (otherIterationNode)
        {
            if (!this->end)
            {
                this->start = new SkipListNode(other.start->data, nullptr, nullptr);
                this->end = this->start;
                thisNodeToSkip = this->start;
            }
            else
            {
                this->end->next = new SkipListNode(otherIterationNode->data, nullptr, nullptr);
                this->end = this->end->next;
                skipStepRemainder++;
                if (skipStepRemainder == skipStep)
                {
                    thisNodeToSkip->skipNext = this->end;
                    thisNodeToSkip = thisNodeToSkip->skipNext;
                    skipStepRemainder = 0;
                }
            }

            otherIterationNode = otherIterationNode->next;
        }
    }

    SkipList(const std::vector<T> &array) : SkipList()
    {
        for (const T &elem : array)
        {
            add(elem);
        }
    }

    ~SkipList()
    {
        while (start)
        {
            SkipListNode *temp = start;
            start = start->next;
            delete temp;
        }
    }

    void add(const T &data)
    {
        if (!start)
        {
            start = new SkipListNode(data, nullptr, nullptr);
            end = start;
        }
        else
        {
            addElementInNonEmptyList(data);
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
        {
            return;
        }

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

        nodeToSkip->skipNext = end;
    }

    bool contains(const T &data)
    {
        SkipListNode *iterationNode = start;

        while (iterationNode)
        {
            if (iterationNode->data == data)
            {
                return true;
            }

            if (canMoveForwardWhenData(iterationNode, data))
            {
                if (canSkipFromElementWhenData(iterationNode, data))
                {
                    iterationNode = iterationNode->skipNext;
                }
                else
                {
                    iterationNode = iterationNode->next;
                }
            }
            else
            {
                return false;
            }
        }
        return false;
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
    void addElementInNonEmptyList(const T data)
    {
        SkipListNode *iteratedNode = start;

        while (canMoveForwardWhenData(iteratedNode, data))
        {
            if (canSkipFromElementWhenData(iteratedNode, data))
            {
                iteratedNode = iteratedNode->skipNext;
            }
            else
            {
                iteratedNode = iteratedNode->next;
            }
        }

        SkipListNode *iteratedNext = iteratedNode->next;
        iteratedNode->next = new SkipListNode(data, iteratedNext, nullptr);
        if (!iteratedNext)
        {
            end = iteratedNode->next;
        }
    }

    bool canSkipFromElementWhenData(const SkipListNode *elem, const T &data)
    {
        return elem->skipNext && elem->skipNext->data <= data;
    }

    bool canMoveForwardWhenData(SkipListNode *elem, const T &data)
    {
        return elem->next && elem->next->data <= data;
    }
};
