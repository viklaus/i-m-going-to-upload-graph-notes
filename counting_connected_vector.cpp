#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100001];
int visited[100001];

void dfs(int k)
{
    visited[k] = 1;
    for (auto x : adj[k])
    {
        if (visited[x] != 1)
            dfs(x);
    }
}

int main()
{
    cout << " enter two number n and e";

    int n, e;
    cin >> n >> e;
    for (int i = 0; i < e; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    int count = 0;
    for (int i = 1; i <= n; i++)
    {
        if (visited[i] != 1)
        {
            dfs(i);
            count++;
        }
    }
    cout << count;
    return 0;
}