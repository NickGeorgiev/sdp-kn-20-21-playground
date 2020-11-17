#ifndef __DLLIST_CPP
#define __DLLIST_CPP

#include "dllist.h"

template <class T>
DLList<T>::DLList() : first(nullptr), last(nullptr)
{
}
template <class T>
DLList<T>::DLList(const DLList<T> &other)
{
    copy(other);
}
template <class T>
DLList<T>::~DLList()
{
    clear();
}
template <class T>
DLList<T> &DLList<T>::operator=(const DLList<T> &other)
{
    if (this != &other)
    {
        clear();
        copy(other);
    }
    return *this;
}

template <class T>
DLList<T> &DLList<T>::operator+=(const T &data)
{
    if (first != nullptr && last != nullptr)
    {
        last = new DLList<T>::box{data, nullptr, last};
        if (last->prev != nullptr)
        {
            last->prev->next = last;
        }
    }
    else
    {
        first = last = new DLList<T>::box{data, nullptr, nullptr};
    }
    return *this;
}
template <class T>

DLList<T> DLList<T>::operator+(const T &data)
{
    DLList<T> result(*this);
    result += data;
    return result;
}
template <class T>
void DLList<T>::clear()
{
    DLList<T>::box *crr = first, *save;
    while (crr != nullptr)
    {
        save = crr;
        crr = crr->next;
        delete save;
        //save = nullptr; //save = nullptr;//taka raboti kato go pisha vmesto delete no ne mislq che trie taka naistina
    }
    last = nullptr;
}
template <class T>
void DLList<T>::copy(const DLList<T> &other)
{
    typename DLList<T>::box *newBox, *current;
    if (other.first == nullptr)
    {
        return;
    }
    current = other.first;
    first = new DLList<T>::box{current->data, nullptr, nullptr};
    last = first;
    current = current->next;
    while (current != nullptr)
    {
        newBox = new DLList<T>::box{current->data, nullptr, last};
        last->next = newBox;
        current = current->next;
        last = newBox;
    }
}
template <class T>
std::ostream &operator<<(std::ostream &out, const DLList<T> &list)
{
    typename DLList<T>::box *current = list.first;
    while (current != nullptr)
    {
        out << current->data << " ";
        current = current->next;
    }
    return out;
}
template <class T>
DLList<T> &DLList<T>::pushInFront(const T &data)
{
    if (first != nullptr && last != nullptr)
    {
        first = new DLList<T>::box{data, first, nullptr};
        if (first->next != nullptr)
        {
            first->next->prev = first;
        }
    }
    else
    {
        first = last = new DLList<T>::box{data, nullptr, nullptr};
    }
    return *this;
}
template <class T>
int DLList<T>::count(int x)
{
    if (first == nullptr)
    {
        return 0;
    }

    DLList<T>::box *current = first;
    int counter = 0;
    while (current != nullptr)
    {
        if (current->data == x)
        {
            counter++;
        }
        current = current->next;
    }
    return counter;
}

template <class T>
void DLList<T>::setData(const T &data)
{
    DLList<T>::box *crr = new DLList<T>::box{data, nullptr, last};
    if (last == nullptr || first == nullptr)
    {
        first = last = crr;
        std::cout << last->data;
    }
    else
    {
        last->next = crr;
        last = crr;
    }
}
// template <class T>
//  typename DLList<T>::box *DLList<T>::range(int x, int y)
// {
//     typename DLList<T>::box *current = first;
//     if ((x > y) || count(x) == 0 || count(y) == 0)
//     {
//         std::cout << "Something is wrong!!!\n";
//         return first;
//     }
//     while (current != nullptr)
//     {
//         if (current->data == x)
//         {
//             first = current;
//             bool is = false;
//             while (!is)
//             {
//                 if (current->data == y)
//                 {
//                     is = true;
//                     last = current;
//                     return first;
//                 }
//                 current = current->next;
//             }
//         }
//         else
//         {
//             current = current->next;
//         }
//     }
// }
template <class T>
T DLList<T>::getData() const
{
    return first->data;
}
template <class T>
typename DLList<T>::box *DLList<T>::getBox() const
{
    return last;
}
template <class T>
typename DLList<T>::box *DLList<T>::getFirst() const
{
    return first;
}
template <class T>
int DLList<T>::size() const
{
    int c = 0;
    DLList::box *current = first;
    while (current != nullptr)
    {
        c++;
        current = current->next;
    }
    return c;
}

template <class T>
void DLList<T>::append(const DLList<T> &other)
{
    if (other.first == nullptr)
    {
        return;
    }
    else if (first == nullptr)
    {
        first = other.first;
    }
    typename DLList<T>::box *current = other.first;
    for (size_t i = 0; i < other.size(); ++i)
    {
        operator+=(current->data);
        current = current->next;
    }
}
template <class T>
DLList<T> &DLList<T>::operator+=(const DLList<T> &other)
{
    append(other);
    return *this;
}

template <class T>
DLList<T> &DLList<T>::reverse()
{
    DLList<T> res;
    DLList<T>::box *current = last;
    for (size_t i = 0; i < size(); ++i)
    {
        res += current->data;
        current = current->prev;
    }
    current = nullptr;
    this->operator=(res);
    return *this;
}

template <class T>
void DLList<T>::deleteAll(const T &data)
{
    if (first == nullptr)
    {
        return;
    }
    DLList::box *crr = first->next, *save;
    if (first->data == data)
    {
        save = first;
        first = first->next;
        first->prev = nullptr;
        delete save;
    }

    while (crr != nullptr)
    {
        if (crr->data == data)
        {
            save = crr;
            crr = crr->next;
            save->prev->next = crr;
            crr->prev = save->prev;
            delete save;
        }
        else
        {
            crr = crr->next;
        }
    }
}
template <class T>
DLList<T> DLList<T>::insertion(const DLList<T> &l1, const DLList<T> &l2)
{
    DLList<T> res;
    DLList<T>::box *list1Head = l1.first;
    DLList<T>::box *list2Head = l2.first;
    while (list1Head && list2Head)
    {
        if (list1Head->data == list2Head->data)
        {
            res += list1Head->data;
            DLList<T>::box *crr = list1Head;
            while (crr->data == list1Head->data)
            {
                list1Head = list1Head->next;
            }
            while (crr->data == list1Head->data)
            {
                list2Head = list2Head->next;
            }
            continue;
        }
        if (list1Head->data < list2Head->data)
        {
            list1Head = list1Head->next;
        }
        else
        {
            list2Head = list2Head->next;
        }
    }
    return res;
}

#endif