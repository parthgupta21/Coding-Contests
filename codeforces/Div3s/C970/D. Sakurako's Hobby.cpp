#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> perm(n + 1);
    string color;
    vector<int> res(n + 1, 0);

    for (int i = 1; i <= n; i++)
    {
        cin >> perm[i];
    }

    cin >> color;

    vector<bool> vis(n + 1, false);

    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            vector<int> cycle;
            int cur = i;
            int blacks = 0;

            while (!vis[cur])
            {
                vis[cur] = true;
                cycle.push_back(cur);
                if (color[cur - 1] == '0')
                {
                    blacks++;
                }
                cur = perm[cur];
            }

            for (int node : cycle)
            {
                res[node] = blacks;
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        cout << res[i] << " ";
    }
    cout << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
