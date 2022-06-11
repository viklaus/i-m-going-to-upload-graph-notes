// Program to print BFS traversal from a given
// source vertex. BFS(int s) traverses vertices
// reachable from s.
#include <bits/stdc++.h>
using namespace std;
// This class represents a directed graph using
// adjacency list representation
// kya karu bhai adat se majboor hooo
class Graph
{
    map<int, list<int>> adj;

public:
    void addEdge(int v, int w);
    void BFS(int s);
};
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
    adj[w].push_back(v);
    // undirected ka bahut bada role hai
}
void Graph::BFS(int s)
{
    // Mark all the vertices as not visited
    map<int, bool> visited;
    // Create a queue for BFS
    queue<int> que;
    // Mark the current node as visited and enqueue it
    visited[s] = true;
    que.push(s);
    while (!que.empty())
    {
        // Dequeue a vertex from queue and print it
        s = que.front();
        cout << s << " ";
        que.pop();
        // Get all adjacent vertices of the dequeued
        // vertex s. If a adjacent has not been visited,
        // then mark it visited and enqueue it
        for (auto x : adj[s])
        {
            if (!visited[x])
            {
                visited[x] = true;
                que.push(x);
            }
        }
    }
}
// Driver program to test methods of graph class
int main()
{
    // Create a graph given in the above diagram
    Graph g;
    int n;
    cout << "enter your vertices size";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        g.addEdge(x, y);
    }
    cout << "Following is Breadth First Traversal "
         << "(starting from vertex 2) \n";
    g.BFS(2);
    return 0;
}
