#include "Trie.cpp"

int main()
{
    Trie<int, char> tr;
    tr.add("koza", 20);
    tr.add("boza", 26);
    tr.add("sisi", 69);
    tr.add("mlqko", 96);
    tr.add("hrana", 1);
    tr.add("niki", 69);

     tr.dfsPrint();
    std::cout << tr.at("koza") << "\n";
}