#ifndef TRIE_CPP_INCLUDED
#define TRIE_CPP_INCLUDED
#include "Trie.h"
template <class ValueType, class KeyType>
Trie<ValueType, KeyType>::Trie() : root(nullptr) {}
template <class ValueType, class KeyType>
void Trie<ValueType, KeyType>::add(const std::string &_key, const ValueType &_value)
{
    if (!root)
    {
        root = new TrieNode;
    }
    typename Trie<ValueType, KeyType>::TrieNode *current = root;
    for (auto element : _key)
    {
        if (!current->children.count(element))
        {
            current->children[element] = new TrieNode;
        }
        current = current->children[element];
    }
    current->value = _value;
    current->endOfWord = true;
}
template <class ValueType, class KeyType>
void Trie<ValueType, KeyType>::add(const std::pair<std::string, ValueType> &pr)
{
    auto [key, value] = pr;
    add(key, value);
}
template <class ValueType, class KeyType>
ValueType Trie<ValueType, KeyType>::at(const std::string &word) const
{
    typename Trie<ValueType, KeyType>::TrieNode *current = root;
    for (auto element : word)
    {
        if (!search(element))
        {
            std::out_of_range("Invalid key");
        }
        current = current->children[element];
    }
    if (!current->endOfWord)
    {
        std::out_of_range("Missing word");
    }
    return current->value;
}
template <class ValueType, class KeyType>
bool Trie<ValueType, KeyType>::search(const KeyType &_key) const
{
    typename Trie<ValueType, KeyType>::TrieNode *current = root;
    return current->children.count(_key);
}
template <class ValueType, class KeyType>
void Trie<ValueType, KeyType>::dfsPrintHelper(Trie<ValueType, KeyType>::TrieNode *r) const
{
    if (!r)
    {
        return;
    }
    // auto [key,n] = r->children;
    //std::unordered_map<KeyType, TrieNode *>::iterator it = r->children.begin();

    if (r->endOfWord)
    {
        std::cout << r->value << "\n";
    }
    for (auto [key, node] : r->children)
    {
        std::cout << key << "\n";
        dfsPrintHelper(node);
    }
}
template <class ValueType, class KeyType>
void Trie<ValueType, KeyType>::dfsPrint() const
{
    dfsPrintHelper(this->root);
}

#endif