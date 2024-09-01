#include <bits/stdc++.h>
using namespace std;

#define f(i, a, b) for (auto i = (a); i < (b); ++i)
#define rep(i, n) f(i, 0, n)
#define rf(i, a, b) for (auto i = (a); i >= (b); --i)
#define rrep(i, n) rf(i, (n)-1, 0)
#define srt(v) sort(v.begin(), v.end())
typedef long long ll;

void solve();
int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}

void solve()
{
    vector<int> freq(26, 0);
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    for (auto c : s)
    {
        freq[c - 'a']++;
    }
    int cnt = 0;
    for (auto x : freq)
    {
        if (x % 2 == 1)
        {
            cnt++;
        }
       
    }
    if( cnt > k+1 )
    {
        cout << "NO" << endl;
    }
    else{
        cout << "YES" << endl;
    }
}