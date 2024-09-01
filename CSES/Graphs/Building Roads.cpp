#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <set>

#define lli long long int

using namespace std;

class DSU
{
private:
    vector<int> parent;
    vector<int> sz;

public:
    DSU(int n)
    {
        parent.resize(n + 1);
        sz.resize(n + 1, 1);

        for (int i = 1; i <= n; i++)
        {
            parent[i] = i;
        }
    }

    int findPar(int node)
    {
        if (node == parent[node])
        {
            return node;
        }

        return parent[node] = findPar(parent[node]);
    }

    void unionBySize(int u, int v)
    {
        u = findPar(u);
        v = findPar(v);

        if (u != v)
        {
            if (sz[u] < sz[v])
            {
                parent[u] = v;
                sz[v] += sz[u];
            }
            else
            {
                parent[v] = u;
                sz[u] += sz[v];
            }
        }
    }
};

int main()
{
    lli n, m;
    cin >> n >> m;

    DSU dsu(n);
    vector<pair<int, int>> roads;

    for (int i = 0; i < m; i++)
    {
        lli a, b;
        cin >> a >> b;

        dsu.unionBySize(a, b);
        roads.push_back({a, b});
    }

    set<int> components;

    for (int i = 1; i <= n; i++)
    {
        components.insert(dsu.findPar(i));
    }
    

    int k = components.size() - 1;

    cout << k << endl;

    if (k >= 1)
    {
        vector<int> rep;

        for (auto it : components)
        {
            rep.push_back(it);
        }

        for (int i = 0; i < k; i++)
        {
            cout << rep[i] << " " << rep[i + 1] << endl;
        }
    }

    return 0;
}
