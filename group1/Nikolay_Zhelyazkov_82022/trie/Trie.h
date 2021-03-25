#ifndef TRIE_H_INCLUDED
#define TRIE_H_INCLUDED
#include <string>
#include <unordered_map>
#include <map>
#include <iostream>
#include <exception>

template <class ValueType, class KeyType>
class Trie
{
private:
    struct TrieNode
    {
        ValueType value;
        bool endOfWord;
        std::unordered_map<KeyType, TrieNode *> children;
        TrieNode(bool _endOfWord = false) : endOfWord(_endOfWord) {}
    };
    TrieNode *root;
    void dfsPrintHelper(TrieNode *) const;

public:
    Trie();
    ~Trie() = default;
    void add(const std::string &, const ValueType &);
    void add(const std::pair<std::string, ValueType> &);
    ValueType at(const std::string &) const;
    bool search(const KeyType &) const;
    void dfsPrint() const;
};

#endif