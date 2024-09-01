#include <bits/stdc++.h>

using namespace std;

#define lli long long int

bool dfs(vector<vector<lli>> &adj, vector<int> &vis, vector<int> &parent, int node)
{
    vis[node] = 1;

    for (auto x : adj[node])
    {
        if (!vis[x])
        {
            vis[x] = 1;
            parent[x] = node;
            if(dfs(adj, vis, parent, x))
                return true;
            
        }
        else
        {
            if (parent[node] != x)

            {
                vector<int> path;
                path.push_back(x);
                for (int i = node; i != x; i = parent[i])
                {
                    path.push_back(i);
                }
                path.push_back(x);

                cout << path.size() << endl;
                reverse(path.begin(), path.end());

                for (auto it : path)
                {
                    cout << it << " ";
                }
                cout << endl;
                return true;
            }
        }
    }
    return false;
}

int main()
{
    lli n, m;
    cin >> n >> m;

    vector<vector<lli>> adj(n + 1);
    vector<int> vis(n + 1, 0);
    vector<int> parent(n + 1, -1);

    for (int i = 0; i < m; i++)
    {
        lli a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            if (dfs(adj, vis, parent, i))
            {
                return 0;
            }
        }
    }
    cout << "IMPOSSIBLE" << endl;
    return 0;
}