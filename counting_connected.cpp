#include <bits/stdc++.h>
using namespace std;

// coding karna kab ka chhod diya hu bhai.
// ab to pyar karne ka time aaya hai.

class graph
{
    void travel_full();

public:
    map<int, bool> visited;
    map<int, list<int>> adj;
    void addedge(int v, int w);
    void DFS(int k);
};

void graph::addedge(int v, int w)
{
    adj[v].push_back(w);
}

void graph::DFS(int k)
{
    visited[k] = true;
    for (auto l : adj[k])
    {
        DFS(l);
    }
}
// n = 6 ;
// 8 5
// 1 2
// 2 3
// 2 4
// 3 5
// 6 7

int main()
{
    cout << " enter your two number n and e.";
    int n, e;
    cin >> n >> e;
    graph g;
    while (e--)
    {
        int x, y;
        cin >> x >> y;
        g.addedge(x, y);
    }
    int count = 0;
    for (int i = 1; i < n; i++)
    {
        if (g.visited[i] == false)
        {
            g.DFS(i);
            count++;
        }
    }
    cout << count;
    return 0;
}
