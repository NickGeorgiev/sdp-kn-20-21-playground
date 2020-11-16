#include "LList.h"

#include <exception>

template<class T>
LList<T>::LList(): first(nullptr), last(nullptr), length(0) {}

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
	try
	{
		if(first)
		{
			Node* current = first;

			while (position > 0 && current)
			{
				current = current->next;
				position--;
			}

			if (!current)
			{
				throw std::runtime_error("Out of bounds!");
			}

			return current;
		}
		else
		{
			throw std::runtime_error("Empty list!");
		}
	}
	catch(const std::runtime_error& e)
	{
		std::cerr << e.what() << '\n';
	}	
}

template<class T>
const size_t LList<T>::size()
{
	return length;

	//size_t counter = 0;
	//Node* current = first;
	//
	//while (current != nullptr)
	//{
	//	current = current->next;
	//	counter++;
	//}
	//
	//return counter;
}

template<class T>
void LList<T>::push_front(const T& x)
{
	first = new Node<T>(x, first);
	if (!last)
	{
		last = first;
	}
	length++;
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
		length--;
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
	length++;
}

template<class T>
void LList<T>::deleteAfter(size_t position)
{
	Node* prev = at(position);
    if (prev->next == nullptr) 
	{
		return;
	}

    Node* toDelete = prev->next;

	if (toDelete == last)
	{
		prev->next = nullptr;
		last = prev;
	}
	else
	{
		prev->next = prev->next->next;
	}

	length--;

	delete toDelete;
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
	length++;
}

template<class T>
void LList<T>::pop_back()
{
	if (last == first)
	{
		pop_front(x);
		return;
	}

	deleteAfter(length-1);
}

template<class T>
void LList<T>::copy(const LList& other)
{   
    Node* current = other->first;

    while (current != nullptr)
    {
        push_back(current->data);
        current = current->next;
    }

	length = other.length;
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
	if (this = *other) 
	{
		return;
	}

    clear();

    copy(other);
}

template<class T>
void LList<T>::print() const
{
    Node* current = first;
	while(current)
	{
		current->print();
		current = current->next;
	}
}

template<class T>
void LList<T>::reverse()
{
	Node* current = first, previous = nullptr, next = nullptr;

	while(current != nullptr)
	{
		next = current->next;
		current->next = previous;
		previous = current;
		current = next;
	}

	first = previous;
}
