#include <bits/stdc++.h>
using namespace std;
class Edge
{
public:
    int src, dest, w;
};
class Graph
{
public:
    int V, E;
    Edge *ed;
};
Graph *creategraph(int v, int e)
{
    Graph *g = new Graph;
    g->V = v;
    g->E = e;
    g->ed = new Edge[e];
    return g;
}
class subset
{
public:
    int par, rank;
};
int find(subset subs[], int i)
{
    if (subs[i].par != i)
        subs[i].par = find(subs, subs[i].par);
    return subs[i].par;
}
void Union(subset subs[], int x, int y)
{
    int xr = find(subs, x);
    int yr = find(subs, y);
    if (subs[xr].rank < subs[yr].rank)
        subs[xr].par = yr;
    else if (subs[xr].rank > subs[yr].rank)
        subs[yr].par = xr;
    else
    {
        subs[yr].par = xr;
        subs[xr].rank++;
    }
}
int comp(const void *a, const void *b)
{
    Edge *a1 = (Edge *)a;
    Edge *b1 = (Edge *)b;
    return a1->w > b1->w;
}
void Kruskal(Graph *g)
{
    int V = g->V;
    Edge result[V];
    int e = 0;
    int i = 0;
    qsort(g->ed, g->E, sizeof(g->ed[0]), comp);
    subset subs[V];
    for (int i = 0; i < V; i++)
    {
        subs[i].par = i;
        subs[i].rank = 0;
    }
    while (e < V - 1 && i < g->E)
    {
        Edge next = g->ed[i++];
        int x = find(subs, next.src);
        int y = find(subs, next.dest);
        if (x != y)
        {
            result[e++] = next;
            Union(subs, x, y);
        }
    }
    cout << "MST: " << endl;
    int cost = 0;
    for (int i = 0; i < e; i++)
    {
        cout << result[i].src << "--" << result[i].dest << endl;
        cost += result[i].w;
    }
    cout << "Cost:" << cost;
}
int main()
{
    int V = 4; // Number of vertices in graph
    int E = 5; // Number of edges in graph
    Graph *graph = creategraph(V, E);

    // add edge 0-1
    graph->ed[0].src = 0;
    graph->ed[0].dest = 1;
    graph->ed[0].w = 10;

    // add edge 0-2
    graph->ed[1].src = 0;
    graph->ed[1].dest = 2;
    graph->ed[1].w = 6;

    // add edge 0-3
    graph->ed[2].src = 0;
    graph->ed[2].dest = 3;
    graph->ed[2].w = 5;

    // add edge 1-3
    graph->ed[3].src = 1;
    graph->ed[3].dest = 3;
    graph->ed[3].w = 15;

    // add edge 2-3
    graph->ed[4].src = 2;
    graph->ed[4].dest = 3;
    graph->ed[4].w = 4;

    // Function call
    Kruskal(graph);
}
