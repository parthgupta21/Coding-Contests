#include <bits/stdc++.h>


using namespace std;
#define lli long long int



void shortest_path(vector<vector<lli>> &adj, int startnode , int end){
    priority_queue<pair<lli, lli>, vector<pair<lli, lli>>, greater<pair<lli, lli>>> pq;
    vector<lli> dist(end + 1, 1e10);
    vector<lli> parent(end + 1, -1);

    pq.push({0, startnode});
    dist[startnode] = 0;

    while(!pq.empty()){
        lli node = pq.top().second;
        pq.pop();

        for(auto x : adj[node]){
            lli neighbour = x;
            
            if(dist[neighbour] > dist[node] + 1){
                dist[neighbour] = dist[node] + 1;

                parent[neighbour] = node;

                pq.push({dist[neighbour], neighbour});
            }
        }
    }


    if(dist[end] == 1e10){
        cout << "IMPOSSIBLE" << endl;
        return;
    }

    else{
        cout << dist[end]+1 << endl;
    }

    vector<int> path;

    for (int i = end; i != -1; i = parent[i]){
        path.push_back(i);
    }

    reverse(path.begin(), path.end());

    for(auto it : path){
        cout << it << " ";
    }

    cout << endl;
}

int main(){
    lli n, m;
    cin >> n >> m;

    vector<vector<lli>> adj(n + 1);

    for (int i = 0; i< m; i++){
        lli u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    shortest_path(adj, 1, n);
    return 0;
}