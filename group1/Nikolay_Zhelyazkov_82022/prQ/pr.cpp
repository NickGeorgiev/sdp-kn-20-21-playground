#include <vector>
#include <iostream>
#include <queue>

std::vector<std::vector<int>> kClosest(std::vector<std::vector<int>> &points, int K)
{
    auto pr = [](std::pair<int, std::vector<int>> p1, std::pair<int, std::vector<int>> p2) { return p1.first > p2.first; };
    std::priority_queue<std::pair<int, std::vector<int>>, std::vector<std::pair<int, std::vector<int>>>, decltype(pr)> pq(pr);

    for (int i = 0; i < points.size(); ++i)
    {
        int d = 0;
        std::vector<int> vr;
        for (int j = 0; j < points[i].size(); ++j)
        {
            vr.push_back(points[i][j]);
            d += (points[i][j] * points[i][j]);
        }
        pq.push(make_pair(d, vr));
    }
    std::vector<std::vector<int>> v;
    while (K > 0)
    {
        v.push_back(pq.top().second);
        pq.pop();
        --K;
    }

    return v;
}

int main()
{
    std::vector<std::vector<int>> v = {{1, 3}, {-2, 2}};
    std::vector<std::vector<int>> res;
    res = kClosest(v, 2);
    for (int i = 0; i < res.size(); ++i)
    {
        for (int j = 0; j < res[i].size(); ++j)
        {
            std::cout << res[i][j] << " ";
        }
        std::cout << "\n";
    }
    return 0;
}