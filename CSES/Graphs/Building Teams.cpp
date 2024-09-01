#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <set>

#define lli long long int

using namespace std;

bool dfs(vector<vector<lli>> &adj, vector<lli> &color,int node, int c)
{

    color[node] = c;

    for(auto x : adj[node]){
        if(color[x] == 0){
            if(!dfs(adj, color, x, 3 - c)){
                return 0;
            }
        }
        else if(color[x] == color[node]){
            return 0;
        }
    }
    return 1;
}

int main()
{

    lli n, m;
    cin >> n >> m;

    vector<vector<lli>> adj(n + 1);

    for (int i = 0; i < m; i++)
    {
        lli a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<lli> color(n + 1, 0);

    

    for(int i = 1; i <= n; i++){
        if(color[i] == 0){
            if(!dfs(adj, color, i, 1))
            {
            cout << "IMPOSSIBLE" << endl;
            return 0;
            }
            
        }
    }

    for (auto i = 1; i <= n; i++)
    {
        cout << color[i] << " ";
    }

    cout << endl;
    return 0;
}