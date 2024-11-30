#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define f(i, a, b) for (auto i = (a); i < (b); ++i)
#define rep(i, n) f(i, 0, n)
#define rf(i, a, b) for (auto i = (a); i >= (b); --i)
#define rrep(i, n) rf(i, (n) - 1, 0)
#define srt(v) sort(v.begin(), v.end())
#define rsrt(v) sort(v.rbegin(), v.rend())
#define print_1D_arr(a, n)            \
    for (long long i = 0; i < n; i++) \
    {                                 \
        cout << a[i] << ' ';          \
    }                                 \
    cout << endl;
#define in_1D_arr(a, n) \
    f(i, 0, n) { cin >> a[i]; }

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
typedef long long int lli;
typedef vector<ll> vll;
typedef vector<lli> vli;
typedef vector<int> vi;
typedef vector<vector<ll>> vvll;
typedef vector<bool> vbol;
const ll mod = 1e9 + 7;
#define N 200000

void solve()
{
    lli n;
    vli a(n);
    lli maxLength = 0;

    cin >> n;

    
    

    in_1D_arr(a, n); 

    lli last[N + 1];
    rep(i, N) last[i + 1] = -2;

    lli l = 0;

    for (lli i = 0; i + 1 < n; i += 2)
    {
        if (a[i] != a[i + 1])
        {
            l = i + 2;
        }
        else
        {
            l = max(l, last[a[i]] + 2);
        }
        maxLength = max(maxLength, i + 2 - l);
        last[a[i]] = i;
    }

    
    rep(i, N) last[i + 1] = -2;
    l = 1;

    for (lli i = 1; i + 1 < n; i += 2)
    {
        if (a[i] != a[i + 1])
        {
            l = i + 2;
        }
        else
        {
            l = max(l, last[a[i]] + 2);
        }
        maxLength = max(maxLength, i + 2 - l);
        last[a[i]] = i;
    }
    cout << maxLength << endl;
}

int main()
{
    lli t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}
