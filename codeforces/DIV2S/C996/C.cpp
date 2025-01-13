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
lli arr[3001][3001];

void solve()
{
    lli n, m;
    string s;
    cin >> n >> m >> s;

    vector<long long> rowSum(n, 0), colSum(m, 0);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
            rowSum[i] += arr[i][j];
            colSum[j] += arr[i][j];
        }
    }

    ll x = 0;
    ll y = 0;
    ll len = s.length();


    for (int i = 0; i <= len; i++)
    {
        
        if (s[i] == 'D')
        {
            arr[x][y] = -1 * rowSum[x];
            colSum[y] += arr[x][y];
            x++;
        }
        else
        {
            arr[x][y] = -1 * colSum[y];
            rowSum[x] += arr[x][y];
            y++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
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