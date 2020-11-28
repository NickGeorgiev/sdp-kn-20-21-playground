#ifndef __SET_CPP
#define __SET_CPP

#include "set.h"

#include <iostream>

template <class T>
void Set<T>::destroy()
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
void Set<T>::copy(const Set<T> &other)
{
    size = 0;
    first = last = nullptr;
    Set::Node *current = other.first;
    while (current)
    {
        add(current->data);
        current = current->next;
    }
}

template <class T>
Set<T>::Set()
{
    first = nullptr;
    last = nullptr;
    size = 0;
}

template <class T>
Set<T>::Set(const Set<T> &other)
{
    copy(other);
}

template <class T>
Set<T> &Set<T>::operator=(const Set<T> &other)
{
    if (this != &other)
    {
        destroy();
        copy(other);
    }
    return *this;
}

template <class T>
Set<T>::~Set()
{
    destroy();
}

template <class T>
void Set<T>::add(const T &data)
{
    if (!first)
    {
        first = new Set::Node();
        first->data = data;

        last = first;
    }
    else
    {
        Set::Node *current = first;

        while (current)
        {
            if (current->data == data)
            {
                return;
            }
            else if (current->data > data)
            {
                break;
            }

            current = current->next;
        }

        Set::Node *temp = new Set::Node();
        temp->data = data;

        if (!current)
        {
            temp->prev = last;
            last->next = temp;
            last = temp;
        }
        else
        {
            temp->prev = current->prev;
            temp->next = current;

            if (current == first)
            {
                first = temp;
            }
            else
            {
                current->prev->next = temp;
            }

            current->prev = temp;
        }
    }
    size++;
}

template <class T>
void Set<T>::remove(const T &data)
{
    
    Set::Node *current = first;

    while (current)
    {
        
        if (current->data == data)
        {

            if (!current->next)
            {
                last = current->prev;
                last->next = nullptr;
            }
            else if (!current->prev)
            {
                first = current->next;
                first->prev = nullptr;
            }
            else
            {
                current->next->prev = current->prev;
                current->prev->next = current->next;
            }
        }
        current = current->next;
    }
    size--;
    
}

template <class T>
void Set<T>::print()
{
    Set::Node *current = first;
    while (current)
    {
        std::cout << current->data << " ";
        current = current->next;
    }
}

template <class T>
Set<T>::Iterator::Iterator(Node *_current, Node *_start, Node *_end) : current{_current}, start{_start}, end{_end} {}

template <class T>
T &Set<T>::Iterator::operator*()
{
    if (current == start->prev || current == end->next)
    {
        throw std::out_of_range("Nil iterator");
    }

    return current->data;
}

template <class T>
typename Set<T>::Iterator &Set<T>::Iterator::operator++()
{
    if (current == start->prev || current == end->next)
    {
        throw std::out_of_range("Nil iterator");
    }

    current = current->next;
    return *this;
}

template <class T>
typename Set<T>::Iterator &Set<T>::Iterator::operator--()
{
    if (current == start->prev || current == end->next)
    {
        throw std::out_of_range("Nil iterator");
    }

    current = current->prev;
    return *this;
}

template <class T>
bool Set<T>::Iterator::operator!=(const Iterator &other) const
{
    return current != other.current;
}

template <class T>
bool Set<T>::Iterator::operator==(const Iterator &other) const
{
    return current == other.current;
}

template <class T>
typename Set<T>::Iterator Set<T>::begin() const
{
    return Set<T>::Iterator(first, first, last);
}

template <class T>
typename Set<T>::Iterator Set<T>::end() const
{
    return Set<T>::Iterator(last->next, first, last);
}

#endif
