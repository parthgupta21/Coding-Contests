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
    lli n;
    cin >> n;

    lli x = n;

    set<int> st;
    vector<pair<int, int>> v;
    map<int, int> mp;

    while (x--)
    {
        lli a, b;
        cin >> a >> b;

        v.pb({a, b});

        if (a == b)
        {
            st.insert(a);
            mp[a]++;
        }
    }

    vi temp(all(st));

    string s = "";

    f(i, 0, n)
    {
        if (v[i].ff == v[i].ss)
        {
            if (mp[v[i].ff] > 1)
            {
                s += '0';
            }
            else
            {
                s += '1';
            }
        }
        else
        {
            lli it1 = lower_bound(all(temp), v[i].ff) - temp.begin();
            lli it2 = lower_bound(all(temp), v[i].ss) - temp.begin();

            if (it1 != temp.size() && it2 != temp.size() && temp[it1] == v[i].ff && temp[it2] == v[i].ss && it2 - it1 + 1 == v[i].ss - v[i].ff + 1)
            {
                s += '0';
            }
            else
            {
                s += '1';
            }
        }
    }
    cout << s << endl;
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