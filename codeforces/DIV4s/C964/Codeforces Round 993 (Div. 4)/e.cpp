#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int k, l1, r1, l2, r2;
    cin >> k >> l1 >> r1 >> l2 >> r2;


    // y = a.p  

    int cnt = 0; // answer 
    for (int p = 1; p <= r2; p *= k)  // -> 1 k k^2 k^3 k^4 ......
    { 
        int lowX = max(l1, (l2 + p - 1) / p); 
        int highX = min(r1, r2 / p);              

        if (lowX <= highX)
        {
            cnt += (highX - lowX + 1); 
        }

        
        if (p > r2 / k)
            break;
    }

    cout << cnt << "\n";
}

int32_t main()
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
