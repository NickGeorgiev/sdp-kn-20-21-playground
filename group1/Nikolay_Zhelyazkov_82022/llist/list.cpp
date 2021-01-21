#include <exception>
#include <stack>
#include <iostream>
template <class T>
struct Node
{
    T data;
    Node<T> *next;
    Node(const T &_data, Node<T> *_next) : data(_data), next(_next) {}
};

template <class T>
Node<T> *reverse(Node<T> *first)
{
    //1 2 3 4
    if (!first)
    {
        return nullptr;
    }
    Node<T> *current = first;
    Node<T> *newL = new Node<T>{first->data, nullptr};
    current = current->next;
    while (current)
    {
        newL = new Node<T>{current->data, newL};
        current = current->next;
    }
    return newL;
}
//1234
//1223334444

template <class T>
void pushN(Node<T> *first)
{
    if (!first)
    {
        return;
    }
    Node<T> *current = first;
    while (current)
    {
        Node<T> *save = current->next;
        int n = current->data;
        for (int i = 0; i < n - 1; ++i)
        {
            current->next = new Node<T>(n, nullptr);
            current = current->next;
        }
        current->next = save;
        current = current->next;
    }
}

template <class T>
void printNode(Node<T> *first)
{
    if (!first)
    {
        return;
    }
    Node<T> *current = first;
    while (current)
    {
        std::cout << current->data << " ";
        current = current->next;
    }
}

// 2 -> 4 -> 3    pushFront 3 , 4 , 2
// 5 -> 6 -> 4

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
void push(ListNode *&first, int el)
{
    if (!first)
    {
        first = new ListNode(el, nullptr);
        return;
    }
    ListNode *current = first;
    while (current->next)
    {
        current = current->next;
    }
    current->next = new ListNode(el, nullptr);
    //return first;
}
ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{

    if (!l1 && !l2)
    {
        return nullptr;
    }
    ListNode *temp1 = nullptr;
    int add = 0;
    int el1 = 0;
    int el2 = 0;
    while (l1 || l2)
    {
        if (!l1)
        {
            el1 = 0;
            el2 = l2->val;
        }
        else if (!l2)
        {
            el1 = l1->val;
            el2 = 0;
        }
        else
        {
            el1 = l1->val;
            el2 = l2->val;
        }

        if (el1 + el2 + add < 10)
        {
            push(temp1, el1 + el2 + add);
            add = 0;
        }
        else
        {
            push(temp1, (el1 + el2 + add) % 10);
            add = 1;
        }
        if (!l1)
        {
            l2 = l2->next;
        }
        else if (!l2)
        {
            l1 = l1->next;
        }
        else
        {
            l1 = l1->next;
            l2 = l2->next;
        }
    }
    if (add == 1)
    {
        push(temp1, add);
    }
    return temp1;
}
/*Example 1:

Input: |1->||2->3->4->5->NULL
Output: 1->3->5->2->4->NULL
Example 2:
1 2 3 4 5 6 7
1 3 2 4 5 6 7

Input: 2->1->3->5->6->4->7->NULL
Output: 2->3->6->7->1->5->4->NULL*/
ListNode *oddEvenList(ListNode *head)
{
    if (!head)
    {
        return nullptr;
    }
    ListNode *first = head;
    ListNode *lastEvenP = head;
    ListNode *firstOdd = head;
    ListNode *current2 = head;
    int count = 1;
    if (!head->next)
    {
        return head;
    }
    current2 = head->next;
    firstOdd = current2;
    head = head->next;

    while (head && head->next)
    {
        if (count % 2 != 0)
        {
            ListNode *current = head->next->next;
            lastEvenP->next = head->next;
            lastEvenP = lastEvenP->next;
            lastEvenP->next = firstOdd;
            current2->next = current;
            current2 = current2->next;
            head = current;
            count += 2;
        }
        else
        {
            head = head->next;
            ++count;
        }
    }
    head = first;
    return head;
}
void printNode(ListNode *first)
{
    if (!first)
    {
        return;
    }
    ListNode *current = first;
    while (current)
    {
        std::cout << current->val << " ";
        current = current->next;
    }
}

template <class T>
T reduce(Node<T> *first, T (*f)(const T &, const T &))
{
    if (!first)
    {
        throw std::out_of_range("No elements");
        return 0;
    }
    else if (!first->next)
    {
        return first->data;
    }
    int res = first->data;
    first = first->next;
    while (first)
    {
        res = f(res, first->data);
        first = first->next;
    }
    return res;
}
template <class T>
T del(const T &l, const T &r)
{
    return l / r;
}
template <class T>
void equalize(Node<std::stack<T>> *first)
{
    if (!first)
    {
        throw std::out_of_range("No elements");
        return;
    }

    Node<std::stack<T>> *current = first;
    int max = first->data.size();
    int secondMax = first->next->data.size();
    Node<std::stack<T>> *maxS = first;
    Node<std::stack<T>> *secondmaxS = first->next;
    current = current->next;
    while (current)
    {
        if (current->data.size() < max - 1)
        {
            while (current->data.size() < max - 1)
            {
                --max;
                current->data.push(maxS->data.top());
                maxS->data.pop();
                if (max < secondMax)
                {
                    Node<std::stack<T>> *temp = maxS;
                    maxS = secondmaxS;
                    secondmaxS = temp;
                    std::swap(max, secondMax);
                }
            }
        }
        if (current->data.size() > secondMax)
        {
            secondmaxS = current;
            secondMax = current->data.size();
        }

        current = current->next;
    }
}
template <class T>
int calc(Node<T> *first)
{
    if (!first)
    {
        return 0;
    }
    int c = 1;
    first = first->next;
    while (first)
    {
        ++c;
        first = first->next;
    }
    return c;
}
template <class T>
void shuffle(Node<T> *first)
{
    if (!first)
    {
        throw std::out_of_range("No elements");
    }
    Node<T> *current = first;
    int count = calc(current);
    int middle = count / 2;
    int tempC = 0;
    while (tempC != middle)
    {
        current = current->next;
        ++tempC;
    }
    Node<T> *saveM = current;
    while (saveM->next)
    {
        Node<T> *newM = saveM->next;
        Node<T> *c = saveM->next->next;
        saveM->next = c;
        newM->next = first;
        first = newM;
    }
    Node<T> *print = first;
    //moga da gi pechatam
    while (print)
    {
        std::cout << print->data << " ";
        print = print->next;
    }
    std::cout << std::endl;
}
template <class T>
void clear(Node<T> *&first)
{
    while (first)
    {
        Node<T> *save = first;
        first = first->next;
        delete save;
    }
}
