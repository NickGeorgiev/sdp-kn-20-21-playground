#include "graph.h"
template <class Vertex, class Weight>
Graph<Vertex, Weight>::Graph(std::vector<std::pair<Edges, Weight>> v)
{
    for (auto &&e : v)
    {
        addEdge(e.first.first, e.first.second, e.second);
    }
}
template <class Vertex, class Weight>
void Graph<Vertex, Weight>::addVertex(const Vertex &v)
{
    vertices.insert(v);
    list[v];
}
template <class Vertex, class Weight>
void Graph<Vertex, Weight>::addEdge(const Vertex &v1, const Vertex &v2, Weight w)
{
    vertices.insert(v1);
    vertices.insert(v2);
    list[v1].insert(v2);
    list[v2];
    edge.insert({std::make_pair(v1, v2), w});
}
template <class Vertex, class Weight>
bool Graph<Vertex, Weight>::hasVertex(const Vertex &v) const
{
    return vertices.count(v) == 1;
}
template <class Vertex, class Weight>
bool Graph<Vertex, Weight>::hasEdge(const Vertex &v1, const Vertex &v2) const
{
    // return edge.contains(std::make_pair(v1, v2));
    return hasVertex(v1) && list.at(v1).count(v2) == 1;
}
template <class Vertex, class Weight>
Weight &Graph<Vertex, Weight>::getEdge(const Vertex &v1, const Vertex &v2)
{
    if (!hasEdge(v1, v2))
    {
        std::invalid_argument("No edge between v1 and v2");
    }
    return edge[std::make_pair(v1, v2)];
}
template <class Vertex, class Weight>
Weight Graph<Vertex, Weight>::getEdge(const Vertex &v1, const Vertex &v2) const
{
    if (!hasEdge(v1, v2))
    {
        std::invalid_argument("No edge between v1 and v2");
    }
    return edge.at(std::make_pair(v1, v2));
}
template <class Vertex, class Weight>
std::set<Vertex> &Graph<Vertex, Weight>::getNeighbours(const Vertex &v)
{
    if (!hasVertex(v))
    {
        std::invalid_argument("No vertex v");
    }
    return list[v];
}
template <class Vertex, class Weight>
void Graph<Vertex, Weight>::pushInVisiting()
{
    for (auto &&vert : vertices)
    {
        visited[vert] = false;
    }
}
template <class Vertex, class Weight>
std::map<Vertex, bool> Graph<Vertex, Weight>::getVisited() const
{
    return this->visited;
}
template <class Vertex, class Weight>
void Graph<Vertex, Weight>::dfsHelper(const Vertex &v)
{
    if (visited[v])
    {
        return;
    }
    visited[v] = true;
    std::cout << v << " ";
    for (auto &&neigh : list[v])
    {
        dfsHelper(neigh);
    }
}
template <class Vertex, class Weight>
void Graph<Vertex, Weight>::dfs(const Vertex &v)
{
    pushInVisiting();
    if (!hasVertex(v))
    {
        std::invalid_argument("No valid vertex");
        return;
    }
    dfsHelper(v);
    std::cout << "\n";
}
template <class Vertex, class Weight>
void Graph<Vertex, Weight>::bfs(const Vertex &v)
{
    pushInVisiting();
    std::queue<Vertex> q;
    if (!hasVertex(v))
    {
        std::invalid_argument("No valid vertex");
        return;
    }
    visited[v] = true;
    q.push(v);
    while (!q.empty())
    {
        Vertex current = q.front();
        std::cout << current << " ";
        q.pop();
        for (auto &&neigh : list[current])
        {
            if (!visited[neigh])
            {
                visited[neigh] = true;
                q.push(neigh);
            }
        }
    }
    std::cout << "\n";
}
