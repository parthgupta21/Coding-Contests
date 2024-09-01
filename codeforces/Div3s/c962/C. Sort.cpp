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
typedef vector<int> vi;
typedef vector<vector<ll>> vvll;
typedef vector<bool> vbol;
const ll mod = 1e9 + 7;
void solve()
{
    lli n, q;
    cin >> n >> q;

    lli a[n + 1][26] = {0};
    lli b[n + 1][26] = {0};

    for (int i = 1; i <= n; i++)
    {
        char x;
        cin >> x;
        a[i][x - 'a']++;

        for (int j = 0; j < 26; j++)
        {
            a[i][j] += a[i - 1][j];
        }
    }

    

    for (int i = 1; i <= n; i++)
    {
        char x;
        cin >> x;
        b[i][x - 'a']++;

        for (int j = 0; j < 26; j++)
        {
            b[i][j] += b[i - 1][j];
        }
    }

    while (q--)
    {
        lli l, r;
        cin >> l >> r;

        l--;

        lli dif = 0;

        f(i, 0, 26)
        {
            int v1 = a[r][i] - a[l][i];
            int v2 = b[r][i] - b[l][i];
            dif += abs(v1 - v2);
        }



        cout << dif / 2 << endl;
    }
}
int main()
{
    lli t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}