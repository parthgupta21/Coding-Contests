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
void solve() {
    int n;
    cin >> n;

    vector<tuple<int, int, int>> ranges;
    for (int i = 0; i < n; i++)
    {
        int l, r;
        cin >> l >> r;
        ranges.emplace_back(l, r, i);
    }

    sort(ranges.begin(), ranges.end());

    set<int> available;
    for (int i = 1; i <= 2 * n; i++)
    {
        available.insert(i);
    }

    vector<char> result(n, '0');

    for (auto x : ranges)
    {
        auto it = available.lower_bound(get<0>(x));
        if (it != available.end() && *it <= get<1>(x))
        {
            result[get<2>(x)] = '1';
            available.erase(it);
        }
    }

    for (char c : result)
    {
        cout << c;
    }
    cout << '\n';
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