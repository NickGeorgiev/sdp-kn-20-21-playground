#include <iostream>
#include "list.h"
#include <exception>

template <class T>
void LList<T>::copy(const LList<T> &other)
{
    size = 0;
    first = last = nullptr;
    Node *other_current = other.first;
    while (other_current)
    {
        add(other_current->data);
        other_current = other_current->next;
    }
}

template <class T>
void LList<T>::destroy()
{
    while (first)
    {
        Node *save = first;
        first = first->next;
        delete save;
    }
    size = 0;
}

template <class T>
LList<T>::LList()
{
    first = nullptr;
    last = nullptr;
    size = 0;
}

template <class T>
LList<T>::LList(const LList<T> &other)
{
    copy(other);
}

template <class T>
LList<T>::~LList()
{
    destroy();
}

template <class T>
LList<T> &LList<T>::operator=(const LList &other)
{
    if (this != &other)
    {
        destroy();
        copy();
    }
    return *this;
}

template <class T>
void LList<T>::add(const T &data)
{
    if (!last)
    {
        last = new LList::Node();
        last->data = data;

        first = last;
    }
    else
    {
        LList::Node *temp = new LList::Node();
        temp->data = data;
        temp->prev = last;

        last->next = temp;

        last = temp;
    }
    size++;
}

template <class T>
void LList<T>::print()
{
    Node *current = first;
    while (current)
    {
        std::cout << current->data << std::endl;
        current = current->next;
    }
}

template <class T>
LList<T>::Iterator::Iterator(Node *_current, Node *_start, Node *_end) : current{_current}, start{_start}, end{_end} {}

template <class T>
T &LList<T>::Iterator::operator*()
{
    if (current == end->next)
    {
        throw std::out_of_range("Nil iterator");
    }
    return current->data;
}

template <class T>
typename LList<T>::Iterator &LList<T>::Iterator::operator++()
{
    if (current == end->next)
    {
        throw std::out_of_range("Nil iterator");
    }
    current = current->next;
    return *this;
}

template <class T>
bool LList<T>::Iterator::operator!=(const Iterator &it) const
{
    return current != it.current;
}

template <class T>
bool LList<T>::Iterator::operator==(const Iterator &it) const
{
    return current == it.current;
}

template <class T>
typename LList<T>::Iterator LList<T>::begin() const
{
    return LList<T>::Iterator(first, first, last);
}

template <class T>
typename LList<T>::Iterator LList<T>::end() const
{
    return LList<T>::Iterator(last->next, first, last);
}
