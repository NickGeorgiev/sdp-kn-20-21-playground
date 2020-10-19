#include "LList.h"

#include <assert.h>

template<class T>
LList<T>::LList()
{
	first = nullptr;
	last = nullptr;
}

template<class T>
LList<T>::LList(const LList& other)
{
    copy(other);
}

template<class T>
LList<T>::~LList()
{
    clear();
}

template<class T>
typename LList<T>::Node* LList<T>::at(size_t position)
{
	assert(first != nullptr);

	Node* current = first;

	while (position > 0 && current != nullptr)
	{
		current = current->next;
		position--;
	}

	assert(current != nullptr);

	return current;
}

template<class T>
size_t LList<T>::size()
{
	size_t counter = 0;
	Node* current = first;

	while (current != nullptr)
	{
		current = current->next;
		counter++;
	}

	return counter;
}

template<class T>
void LList<T>::push_front(const T& x)
{
	first = new Node<T>(x, first);
	if (last == nullptr)
	{
		last = first;
	}
}

template<class T>
void LList<T>::pop_front()
{
	if (first != nullptr)
	{
		
		Node* tmp = first;
		first = first->next;
		delete tmp;
		if (first == nullptr)
		{
			last = nullptr;
		}
	}
}

template<class T>
void LList<T>::insertAfter(const T& x, size_t position)
{
	Node* prev = at(position);

	prev->next = new Node(x, prev->next);
	if (prev == last)
	{
		last = last->next;
	}
}

template<class T>
void LList<T>::deleteAfter(size_t position)
{
	Node* prev = at(position);
    if (prev->next == nullptr) return;
	
    Node* save = prev->next;
	prev->next = prev->next->next;

	if (save == last)
	{
		last = prev;
	}

	delete save;
}

template<class T>
void LList<T>::push_back(const T& x)
{
	if (first == nullptr)
	{
		push_front(x);
		return;
	}
	last = last->next = new Node(x, nullptr);
}

template<class T>
void LList<T>::copy(const LList& other)
{
    if (this = *other) return;

    clear();
    
    Node* current = other->first;

    while (current != nullptr)
    {
        push_back(current->data);
        current = current->next;
    }
}

template<class T>
void LList<T>::clear()
{
    Node* current = first;

    while(current != nullptr)
    {
        current = current->next;
        delete first;
        first = current;
    }
}

template<class T>
T& LList<T>::operator[] (size_t position)
{
	return at(position)->data;
}

template<class T>
T LList<T>::operator[] (size_t position) const
{
	return at(position)->data;
}


template<class T>
LList<T>& LList<T>::operator= (const LList& other)
{
    copy(other);
}

template<class T>
void LList<T>::print() const
{
    
}