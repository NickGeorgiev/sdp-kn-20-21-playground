#include "skipList.h"
#include <math.h>

skipList::skipList() : first(nullptr)
{
}

skipList::~skipList()
{
    delete_helper();
}

skipList::skipList(const skipList &other_list)
{
    copy_helper(other_list);
}

skipList &skipList::operator=(const skipList &other_list)
{
    copy_helper(other_list);
    return *this;
}

void skipList::find_size()
{
    size = 0;
    Node *current_element = first;
    while (current_element)
    {
        size++;
        current_element = current_element->next;
    }
}

void skipList::delete_helper()
{
    Node *current_element = first;
    Node *current_anchor = nullptr;

    while (current_element)
    {
        current_anchor = current_element;
        current_element = current_element->next;
        delete current_anchor;
    }
}

void skipList::copy_helper(const skipList &other_list)
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

void skipList::add_element(const int &new_element)
{
    int element_position = position(new_element);

    if (first == nullptr || element_position == 0)
    {
        first = new Node{new_element, first, nullptr};
    }
    else
    {
        Node *current_element = first;

        for (size_t i = 0; i < element_position - 1; i++)
        {
            current_element = current_element->next;
        }

        Node *new_node = new Node{new_element, current_element->next, nullptr};
        current_element->next = new_node;
    }
}

int skipList::position(const int &new_element) const
{
    Node *current_node = first;
    int counter = 0;
    while (current_node)
    {
        if (current_node->data < new_element)
        {
            counter++;
        }
        current_node = current_node->next;
    }
    return counter;
}
void skipList::print() const
{
    Node *current_element = first;
    while (current_element)
    {
        std::cout << current_element->data << " ";
        current_element = current_element->next;
    }
    std::cout << std::endl;
}

void skipList::optimise()
{
    find_size();
    int element_skip = sqrt(size);
    int counter = 0;

    Node *current_element = first;
    Node *anchor_node = first;
    while (current_element)
    {
        if (counter % element_skip == 0 || current_element->next == nullptr)
        {
            anchor_node->skip = current_element;
            anchor_node = current_element;
        }
        counter++;
        current_element = current_element->next;
    }
}

void skipList::skip_print() const
{
    Node *current_element = first;
    while (current_element)
    {
        std::cout << current_element->data << " ";
        current_element = current_element->skip;
    }
}