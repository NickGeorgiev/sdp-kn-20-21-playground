#ifndef GRAPH_INCLUDED
#define GRAPH_INCLUDED
#include <map>
#include <vector>
#include <set>
#include <exception>
#include <iostream>
#include <queue>
template <class Vertex = int, class Weight = int>
class Graph
{
private:
    std::set<Vertex> vertices;
    using Neighbours = std::set<Vertex>;
    using Edges = std::pair<Vertex, Vertex>;
    std::map<Vertex, Neighbours> list;
    std::map<Edges, Weight> edge;
    std::map<Vertex, bool> visited;
    void dfsHelper(const Vertex &v);

public:
    void pushInVisiting();
    Graph() = default;
    Graph(std::vector<std::pair<Edges, Weight>>);
    ~Graph() = default;
    void addVertex(const Vertex &v);
    void addEdge(const Vertex &v1, const Vertex &v2, Weight w);
    bool hasVertex(const Vertex &v) const;
    bool hasEdge(const Vertex &v1, const Vertex &v2) const;
    Weight &getEdge(const Vertex &v1, const Vertex &v2);
    Weight getEdge(const Vertex &v1, const Vertex &v2) const;
    std::set<Vertex> &getNeighbours(const Vertex &v);
    std::map<Vertex, bool> getVisited() const;

    void dfs(const Vertex &v);
    void bfs(const Vertex &v);
};

#endif