#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll dx[] = {-1, 0, 1, 0};
ll dy[] = {0, 1, 0, -1};


bool inR(int x, int y, int n, int m){
    if (x < 0 || x >= n || y < 0 || y >= m)
    {
        return false;
    }
    return true;

}

void dfs(ll x, ll y, vector<string> &v, vector<vector<ll>> &vis, ll n, ll m)
{
    vis[x][y] = 1;

    for (int i = 0; i < 4; i++){
        ll nx = x + dx[i];
        ll ny = y + dy[i];


        if( inR(nx,ny,n,m) and v[nx][ny] != '#' and vis[nx][ny] == 0){
            dfs(nx, ny, v, vis, n, m);
        }
    }
}
    int main()
    {

        ll n, m;
        cin >> n >> m;
        vector<string> v(n);

        vector<vector<ll>> vis(n, vector<ll>(m, 0));

        for (auto &i : v)
        {
            cin >> i;
        }

        ll cnt = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (v[i][j] == '#')
                    continue;
                if (vis[i][j] == 1)
                    continue;

                dfs(i, j, v, vis, n, m);

                cnt++;
            }
        }
        cout << cnt << endl;
    }
