#include<bits/stdc++.h>

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
#define rrep(i, n) rf(i, (n)-1, 0)
#define srt(v) sort(v.begin(), v.end())
#define rsrt(v) sort(v.rbegin(), v.rend())
#define print_1D_arr(a, n) for (long long i = 0; i < n; i++) { cout << a[i] << ' '; } cout << endl;
#define in_1D_arr(a,n) f(i,0,n){cin>>a[i];}

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
    lli n;

    cin >> n;

    vector<long long> a(n + 1, 0); // Prefix sum array

    // Read input and build prefix sums
    for (int i = 1; i <= n; ++i)
    {
        int x;
        cin >> x;
        a[i] = a[i - 1] + x;
    }

    string s;
    cin >> s;

    lli l = 0, r = n - 1;
    lli ans = 0;

    while(l < r){
        while(l < n and s[l] == 'R'){
            l++;
        }
        while(r >= 0 and s[r] == 'L'){
            r--;
        }


        if(l < r){
            ans += a[r + 1] - a[l];
            l++;
            r--;
        }
    }

    f(i, 0, n+1){
        cout << a[i] << " ";
    }
    cout << endl;

    cout << ans << endl;
}
int main() {
    lli t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}


// 