#include "graph.cpp"

int main()
{
    //std::vector<std::pair<std::pair<int,int>>,int>>v;
    //v.push_back(std::make_pair(std::make_pair(1, 3), 0));
    Graph<int, int> g({std::make_pair(std::make_pair(1, 3), 0), std::make_pair(std::make_pair(1, 2), 0), std::make_pair(std::make_pair(3, 1), 0),
                       std::make_pair(std::make_pair(3, 2), 0), std::make_pair(std::make_pair(2, 1), 0), std::make_pair(std::make_pair(2, 3), 0), std::make_pair(std::make_pair(2, 5), 0),
                       std::make_pair(std::make_pair(2, 6), 0), std::make_pair(std::make_pair(2, 4), 0), std::make_pair(std::make_pair(5, 2), 0), std::make_pair(std::make_pair(5, 6), 0), std::make_pair(std::make_pair(6, 2), 0),
                       std::make_pair(std::make_pair(6, 7), 0), std::make_pair(std::make_pair(7, 6), 0), std::make_pair(std::make_pair(4, 2), 0)});

    // g.addEdge(1, 3, 0);
    // g.addEdge(1, 2, 0);
    // g.addEdge(3, 1, 0);
    // g.addEdge(3, 2, 0);
    // g.addEdge(2, 1, 0);
    // g.addEdge(2, 3, 0);
    // g.addEdge(2, 5, 0);
    // g.addEdge(2, 6, 0);
    // g.addEdge(2, 4, 0);
    // g.addEdge(5, 2, 0);
    // g.addEdge(5, 6, 0);
    // g.addEdge(6, 2, 0);
    // g.addEdge(6, 7, 0);
    // g.addEdge(7, 6, 0);
    // g.addEdge(4, 2, 0);

    // std::cout << "1-> ";
    // for (auto &&el : g.getNeighbours(1))
    // {
    //     std::cout << el << " -> ";
    // }
    // std::cout << std::endl;
    // std::cout << g.getEdge(2, 3);

    g.pushInVisiting();
    g.dfs(1);
    g.pushInVisiting();
    g.dfs(2);
    g.pushInVisiting();
    g.bfs(1);
    g.pushInVisiting();
    g.bfs(5);
}