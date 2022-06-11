#include <bits/stdc++.h>
using namespace std;

class graph
{
public:
    map<int, bool> visited;
    map<int, list<int>> adj;
    void addEdge(int v, int w);
    void DFS(int v);
};
void graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
}
void graph::DFS(int v)
{
    visited[v] = true;
    cout << v << " ";
    list<int>::iterator it;
    for (it = adj[v].begin(); it != adj[v].end(); it++)
    {
        if (visited[*it] != true)
            DFS(*it);
    }
}
// hello love
// i m helpless
int main()
{
    graph g;
    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    // g.addEdge(1, 4);
    g.addEdge(2, 3);
    // g.addEdge(3, 4);
    g.DFS(0);
    return 0;

    // traversal of 0 is : 0->1->2->3->4;
    // even if i has disconnected the link between (1, 4);and (3, 4) i will be able to
    // get that above transversal.
}