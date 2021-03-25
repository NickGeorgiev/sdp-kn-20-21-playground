#include <unordered_map>
#include <vector>
#include <iostream>
#include <string>
std::vector<int> twoSum(std::vector<int> &nums, int target)
{
    std::unordered_map<int, int> m;
    int count = 0;
    std::vector<int> res;
    for (auto &&el : nums)
    {
        if (m.count(target - el))
        {
            res.push_back(m[target - el]);
            res.push_back(count);
            return res;
        }
        m[el] = count;
        ++count;
    }
    return res;
}
int singleNumber(std::vector<int> &nums)
{
    std::unordered_map<int, int> m;
    std::unordered_map<int, int> v;
    for (auto &&el : nums)
    {
        if (!m.count(el) && !v.count(el))
        {
            m[el] = 1;
        }
        else
        {
            m.erase(el);
            if (!v.count(el))
            {
                v[el] = 1;
            }
        }
    }
    return m.begin()->first;
}
int singleNumber2(std::vector<int> &nums)
{
    std::unordered_map<int, int> m;
    for (auto &&el : nums)
    {
        if (m.count(el))
        {
            ++m[el];
        }
        else
        {
            m[el] = 1;
        }
    }
    for (auto &&el : nums)
    {
        if (m[el] == 1)
        {
            return el;
        }
    }
    return 0;
}
int lengthOfLongestSubstring(std::string s)
{
    std::unordered_map<char, bool> m;

    if (s.empty())
    {
        return 0;
    }
    if (s.size() == 1)
    {
        return 1;
    }
    int max = 0;
    int cur = 0;
    for (int i = 0; i < s.size() - 1; ++i)
    {
        for (int j = i; j < s.size(); ++j)
        {
            if (!m.count(s[j]))
            {
                m[s[j]] = true;
                ++cur;
            }
            else
            {
                max = cur > max ? cur : max;
                m.clear();
                cur = 0;
                break;
            }
        }
    }
    return cur > max ? cur : max;
}
int lengthOfLongestSubstringFaster(std::string s)
{

    if (s.empty())
    {
        return 0;
    }

    std::unordered_map<char, int> m;
    int len = INT_MIN;
    int c = 0;
    int rep = 0;
    while (c < s.size())
    {

        if (m[s[c]] > 0)
        {
            --m[s[rep]];
            ++rep;
        }
        else if (c < s.size() && m[s[c]] == 0)
        {
            ++m[s[c]];
            ++c;

            len = max(len, c - rep);
        }
    }
    return len;
}
int main()
{
    std::vector<int> v = {1};
    // std::vector<int> res = twoSum(v, 6);
    // for (auto &&el : res)
    // {
    //     std::cout << el << " ";
    // }
    // std::cout << singleNumber(v);
    std::cout << lengthOfLongestSubstring("jbpnbwwd");
    return 0;
}