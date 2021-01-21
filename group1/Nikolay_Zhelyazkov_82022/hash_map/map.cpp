#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <set>
#include <unordered_map>
#include <algorithm>

std::vector<std::string> compressWords(std::string str)
{
    std::vector<std::string> result;
    std::string word;
    for (auto &&s : str)
    {
        if (s == ' ' || s == '!' || s == '.' || s == ',')
        {
            if (!word.empty())
            {
                result.push_back(word);
                word = "";
            }
        }
        else if (s == '(' || s == ')')
        {
            continue;
        }

        else
        {
            word += s;
        }
    }
    result.push_back(word);
    return result;
}

int countUniqueWords(std::string t1, std::string t2)
{
    std::vector<std::string> words = compressWords(t2);
    std::vector<std::string> words1 = compressWords(t1);
    std::unordered_map<std::string, bool> m;
    int res = 0;
    for (auto &&word : words1)
    {
        if (!m.count(word))
        {
            m[word] = false;
        }
    }

    for (auto &&word : words)
    {

        if (m.count(word) && !m[word])
        {
            ++res;
            m[word] = true;
        }
    }
    return res;
}
int countWords(std::string t1, std::string t2)
{
    std::vector<std::string> words = compressWords(t2);
    std::vector<std::string> words1 = compressWords(t1);
    std::unordered_map<std::string, bool> m;
    int res = 0;
    for (auto &&word : words1)
    {
        if (!m.count(word))
        {
            m[word] = true;
        }
    }

    for (auto &&word : words)
    {

        if (m.count(word))
        {
            ++res;
        }
    }
    return res;
}
template <typename T>
void print(std::vector<T> result)
{
    for (auto &&word : result)
    {
        std::cout << word << " ";
    }
    std::cout << "\n";
}

std::string mostCommonWord(std::string &text)
{
    int maxSize = 0;
    std::string maxCW = "";
    std::vector<std::string> words = compressWords(text);
    std::unordered_map<std::string, int> m;
    for (auto &&word : words)
    {
        if (!m.count(word) && word.size() > 3)
        {
            m[word] = 1;
        }
        else if (word.size() > 3)
        {
            ++m[word];
        }
        if (m[word] > maxSize)
        {
            maxSize = m[word];
            maxCW = word;
        }
    }
    return maxCW;
}
void isHaveDifIJ(int n)
{
    std::unordered_map<int, int> m;

    for (int i = 0; i < n; ++i)
    {
        int a, b;
        std::cin >> a >> b;
        if (m.count(a) && b != m[a])
        {
            std::cout << "YES\n";
            return;
        }
        else if (!m.count(a))
        {
            m[a] = b;
        }
    }
    std::cout << "NO\n";
}
void transformV(std::vector<std::string> &v)
{
    for (auto &&word : v)
    {
        transform(word.begin(), word.end(), word.begin(), ::tolower);
    }
}

int uniqueMorseRepresentations(const std::vector<std::string> &words)
{
    std::vector<std::string> morzez = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};
    std::unordered_map<std::string, bool> morze;
    int count = 0;
    std::string current = "";
    for (auto &&word : words)
    {
        for (auto &&s : word)
        {

            current += morzez[s - 'a'];
        }
        std::cout << current << "\n";
        if (!morze.count(current))
        {
            ++count;
            morze[current] = true;
        }

        current = "";
    }
    return count;
}

int main(int argc, char** argv)
{
    std::string t2 = "Ideally, the hash function will assign each key to a unique bucket, but thissituation is rarely achievable in practice usually some keys will hash to the same bucket";
    // std::string t1 = "In computing, a hash table hash map is a data structure used to implementan associative array, a structure that can map keys to values. A hash tableuses a hash function to compute an index into an array of buckets or slots,from which the correct value can be found.";
    // std::string a = "Hello world how are u";
    // std::string b = "Hey world  are u gay";
    // print(compressWords(t1));
    // std::cout << "------------------------\n";
    // print(compressWords(t2));
    // std::cout << "--------\n";
    // std::cout << countUniqueWords(t1, t2) << std::endl;
    // std::string c = "In computing, a (hash table) hash map; is a data structure used to implementan associative array, a structure that can map keys to values. A hash tableuses a hash function to compute an index into an array of buckets or slots,from which the correct value can be found.";
    // std::cout << mostCommonWord(c) << std::endl;
    //isHaveDifIJ(3);

    //     std::vector<std::string> v = compressWords(t2);
    //     transformV(v);
    //    transform(v.begin(), v.end(), std::back_inserter(v2), [](std::string s){ return s.length ();});
    //     print(v);
    std::cout << uniqueMorseRepresentations({"aittjje", "auyyn", "lqtktn", "lmjwn"});
  
  
    return 0;
}