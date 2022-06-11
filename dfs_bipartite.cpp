#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100001];
int visited[100001];
int color[100001];
bool dfs(int v, int c)
{
    color[v] = c;
    for (auto child : adj[v])
    {
        if (!visited[child])
        {
            visited[child] = 1;
            if (dfs(child, c ^ 1) == false)
                return false;
        }
        else
        {
            if (color[v] == color[child])
                return false;
        }
    }
    return true;
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
    for (int i = 1; i <= n; i++)
    {
        if (visited[i] != 1)
        {
            if (dfs(i, 0) == false)
            {

                cout << "NO";
                return 0;
            }
        }
    }
    cout << "yes";
    return 0;
}
