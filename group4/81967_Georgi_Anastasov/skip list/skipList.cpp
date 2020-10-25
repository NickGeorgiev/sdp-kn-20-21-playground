#include "SkipList.h"
#include <math.h>

SkipList::SkipList() : first(nullptr), size(0)
{
}

SkipList::~SkipList()
{
    delete_helper();
}

SkipList::SkipList(const SkipList &other_list)
{
    copy_helper(other_list);
}

SkipList &SkipList::operator=(const SkipList &other_list)
{
    copy_helper(other_list);
    return *this;
}

size_t SkipList::get_size() const
{
    return size;
}

void SkipList::delete_helper()
{
    Node *current_element = first;
    Node *current_anchor = nullptr;
    size = 0;
    while (current_element)
    {
        current_anchor = current_element;
        current_element = current_element->next;
        delete current_anchor;
    }
}

void SkipList::copy_helper(const SkipList &other_list)
{
    if (first != other_list.first)
    {
        delete_helper();

        Node *current_other_element = other_list.first;
        while (current_other_element)
        {
            add_element(current_other_element->data);
            current_other_element = current_other_element->next;
        }
    }
}

void SkipList::add_element(const int &new_element)
{
    if (!member(new_element))
    {
        return;
    }

    Node *element_position = position(new_element);

    if (first == nullptr || element_position == nullptr)
    {
        first = new Node{new_element, first, nullptr};
    }
    else
    {
        element_position->next = new Node{new_element, element_position->next, nullptr};
    }

    size++;
    optimise();
}

SkipList::Node *SkipList::position(const int &new_element) const
{
    if (first == nullptr || new_element <= first->data)
    {
        return nullptr;
    }

    Node *current_node = first;

    while (current_node->skip && current_node->skip->data < new_element)
    {
        current_node = current_node->skip;
    }

    while (current_node->next && current_node->next->data < new_element)
    {
        current_node = current_node->next;
    }

    return current_node;
}

bool SkipList::member(const int &new_element) const
{
    if (first == nullptr)
    {
        return true;
    }

    Node *current_node = first;

    while (current_node->skip)
    {
        if (new_element == current_node->data)
        {
            return false;
        }
        current_node = current_node->skip;
    }

    while (current_node->next)
    {
        if (new_element == current_node->data)
        {
            return false;
        }
        current_node = current_node->next;
    }

    return true;
}

void SkipList::print() const
{

    Node *current_element = first;
    while (current_element)
    {
        std::cout << current_element->data << " ";
        current_element = current_element->next;
    }
    std::cout << std::endl;
}

void SkipList::optimise()
{
    if (size == 1)
    {
        return;
    }

    int element_skip = sqrt(size);
    int counter = 0;

    Node *current_element = first;
    Node *anchor_node = first;
    while (current_element)
    {
        current_element->skip = nullptr;
        if (counter % element_skip == 0 || current_element->next == nullptr)
        {
            anchor_node->skip = current_element;
            anchor_node = current_element;
        }
        counter++;
        current_element = current_element->next;
    }
}

void SkipList::skip_print() const
{
    Node *current_element = first;
    while (current_element)
    {
        std::cout << current_element->data << " ";
        current_element = current_element->skip;
    }
}
