#include <bits/stdc++.h>
using namespace std;
class AdjListNode
{
    int v;
    int weight;

public:
    AdjListNode(int _v, int _w)
    {
        v = _v;
        weight = _w;
    }
    int getV() { return v; }
    int getWeight() { return weight; }
};

// Class to represent a graph using adjacency list
// representation
class Graph
{
    int V;
    list<AdjListNode> *adj;

    // A function used by longestPath
    void topologicalSortUtil(int v, bool visited[],
                             stack<int> &s);

public:
    Graph(int V); // Constructor
    ~Graph();     // Destructor

    // function to add an edge to graph
    void addEdge(int u, int v, int weight);

    // Finds longest distances from given source vertex
    void longestPath(int s);
};

Graph::Graph(int V) // Constructor
{
    this->V = V;
    adj = new list<AdjListNode>[V];
}

Graph::~Graph() // Destructor
{
    delete[] adj;
}

void Graph::addEdge(int u, int v, int weight)
{
    AdjListNode node(v, weight);
    adj[u].push_back(node);
}
void Graph::topologicalSortUtil(int v, bool visited[], stack<int> &s)
{
    visited[v] = true;
    list<AdjListNode>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
    {
        AdjListNode node = *i;
        if (!visited[node.getV()])
            topologicalSortUtil(node.getV(), visited, s);
    }
    s.push(v);
}
void Graph::longestPath(int src)
{
    stack<int> s;
    int dist[V] = {INT_MIN};
    bool visited[V] = {false};
    for (int i = 0; i < V; i++)
        if (visited[i] == false)
            topologicalSortUtil(i, visited, s);
    for (int i = 0; i < V; i++)
        dist[i] = INT_MIN;
    dist[src] = 0;
    while (s.empty() == false)
    {
        int u = s.top();
        s.pop();
        list<AdjListNode>::iterator i;
        if (dist[u] != INT_MIN)
        {
            for (i = adj[u].begin(); i != adj[u].end(); ++i)
            {

                if (dist[i->getV()] < dist[u] + i->getWeight())
                    dist[i->getV()] = dist[u] + i->getWeight();
            }
        }
    }
    for (int i = 0; i < V; i++)
        (dist[i] == INT_MIN) ? cout << "INF " : cout << dist[i] << " ";
}
int main()
{
    Graph g(6);
    g.addEdge(0, 1, 5);
    g.addEdge(0, 2, 3);
    g.addEdge(1, 3, 6);
    g.addEdge(1, 2, 2);
    g.addEdge(2, 4, 4);
    g.addEdge(2, 5, 2);
    g.addEdge(2, 3, 7);
    g.addEdge(3, 5, 1);
    g.addEdge(3, 4, -1);
    g.addEdge(4, 5, -2);

    int s = 1;
    cout << "Following are longest distances from "
            "source vertex "
         << s << " \n";
    g.longestPath(s);

    return 0;
}