#include "HashMap.h"
template <class Keys, class Values>
HashMap<Keys, Values>::HashMap(size_t _size, std::function<size_t(const Keys &)> _h) : size(_size), hash(_h)
{
    table = new HashMap<Keys, Values>::Box *[size];
    for (int i = 0; i < size; ++i)
    {
        table[i] = nullptr;
    }
}
template <class Keys, class Values>
typename HashMap<Keys, Values>::Box *HashMap<Keys, Values>::locate(size_t index, const Keys &key) const
{
    typename HashMap<Keys, Values>::Box *current = table[index];
    while (current && current->key != key)
    {
        current = current->next;
    }
    return current;
}
template <class Keys, class Values>
Values &HashMap<Keys, Values>::operator[](const Keys &key)
{
    size_t index = hash(key) % size;
    typename HashMap<Keys, Values>::Box *kvPair = locate(index, key);
    if (kvPair != nullptr)
    {
        return kvPair->val;
    }
    else
    {
        table[index] = new HashMap<Keys, Values>::Box{key, Values(), table[index]};
        return table[index]->val;
    }
}
template <class Keys, class Values>
Values HashMap<Keys, Values>::operator[](const Keys &key) const
{
    size_t index = hash(key) % size;
    typename HashMap<Keys, Values>::Box *kvPair = locate(index, key);
    if (kvPair == nullptr)
    {
        std::out_of_range("Nullptr kvpair");
    }
    return kvPair->val;
}
template <class Keys, class Values>
bool HashMap<Keys, Values>::hasKey(const Keys &key) const
{
    size_t index = hash(key) % size;
    typename HashMap<Keys, Values>::Box *kvPair = locate(index, key);
    return kvPair != nullptr;
}
template <class Keys, class Values>
HashMap<Keys, Values>::Iterator::Iterator(Box **_table, size_t _size) : table(_table), size(_size)
{
    row = 0;
    column = nullptr;
    if (!table)
    {
        return;
    }
    size_t i = 0;
    while (i < size && !table[i])
    {
        ++i;
    }
    if (i < size)
    {
        row = i;
        column = table[i];
    }
}
template <class Keys, class Values>
Keys HashMap<Keys, Values>::Iterator::operator*() const
{
    if (!column)
    {
        std::out_of_range("Invalid column");
    }
    return column->key;
}
template <class Keys, class Values>
typename HashMap<Keys, Values>::Iterator &HashMap<Keys, Values>::Iterator::operator++()
{
    if (!column)
    {
        std::out_of_range("Invalid column");
    }
    column = column->next;
    if (!column)
    {
        ++row;
        while (row < size && !table[row])
        {
            ++row;
        }
        if (row < size)
        {
            column = table[row];
        }
    }
    return *this;
}
template <class Keys, class Values>
bool HashMap<Keys, Values>::Iterator::operator!=(const typename HashMap<Keys, Values>::Iterator &other) const
{
    return column != other.column;
}
template <class Keys, class Values>
typename HashMap<Keys, Values>::Iterator HashMap<Keys, Values>::begin() const
{
    return HashMap<Keys, Values>::Iterator(table, size);
}
template <class Keys, class Values>
typename HashMap<Keys, Values>::Iterator HashMap<Keys, Values>::end() const
{
    return HashMap<Keys, Values>::Iterator(nullptr, size);
}
template <class Keys, class Values>
void HashMap<Keys, Values>::clear()
{
    for (int i = 0; i < size; ++i)
    {
        while (table[i])
        {
            pop(i);
        }
    }
}
template <class Keys, class Values>
void HashMap<Keys, Values>::pop(size_t pos)
{
    if (table[pos])
    {
        std::out_of_range("Invalid column");
    }
    typename HashMap<Keys, Values>::Box *current = table[pos]->next;
    std::cout << table[pos]->val<<" ";
    delete table[pos];
    std::cout << "Deleted\n";
    table[pos] = current;
}

template <class Keys, class Values>
HashMap<Keys, Values>::~HashMap()
{
    clear();
}