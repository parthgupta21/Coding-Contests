#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll dx[] = {-1, 0, 1, 0};
ll dy[] = {0, 1, 0, -1};

bool in_range(int x, int y, int m, int n){
    if( x < 0 or x >= n or y < 0 or y >= m){
        return false;
    }
    return true;
}


int main(){
    ll n, m;
    cin >> n >> m;

    vector<string> a(n);

    for(auto &x : a){
        cin >> x;
    }

    vector<vector<ll>> vis(n, vector<ll>(m, 0));
    queue<pair<ll, ll>> q;
    ll cnt = 0;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if(vis[i][j] == 1){
                continue;
            }

            else if(a[i][j] == '#'){
                continue;
            }

            q.push({i, j});
            vis[i][j] = 1;
            cnt++;
            while(!q.empty()){
                ll x = q.front().first;
                ll y = q.front().second;

                q.pop();

                for (int k = 0; k < 4; k++){
                    ll nx = x + dx[k];
                    ll ny = y + dy[k];

                    if(in_range(nx, ny, m, n) and a[nx][ny] != '#' and vis[nx][ny] == 0){
                        q.push({nx, ny});
                        vis[nx][ny] = 1;
                    }
                }
            }
        }
    }
    cout << cnt << endl;
}


