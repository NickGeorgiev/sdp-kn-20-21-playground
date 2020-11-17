#include <list>
#include <iostream>

std::list<int> &rev(std::list<int> &list, int x, int y)
{
    int can = y-1;
    std::list<int>::iterator ptr;
    if (x <= 0)
    {
        return list;
    }
    int count = y;
    int d = list.front();
    list.pop_front();
    int oth = list.front();
    list.pop_front();
    list.push_front(d);
    list.push_front(oth);

    std::list<int>::iterator it = list.begin();
    for (size_t i = 0; i < x + 2; i++)
    {
        it++;
    }
    for (size_t i = x + 2; i < list.size(); i += x)
    {
        if (i + 1 >= list.size())
        {
            return list;
        }
        if(can==0){
            return list;
        }
        int data = *it;
        std::list<int>::iterator other = it;
        other++;
        list.erase(it);
        it = other;
        it++;
        list.insert(it, data);
        can--;
        
    }
    return list;
}
int main()
{
    std::list<int> l{1, 2, 3, 4, 5};
    std::list<int> l2;
    int n, x, y;
    std::cin >> n >> x >> y;

    for (size_t i = 0; i < n; ++i)
    {
        int num;
        std::cin >> num;
        l2.push_back(num);
    }

    l = rev(l2, x, y);
    for (auto &&i : l)
    {
        std::cout << i << " ";
    }
}