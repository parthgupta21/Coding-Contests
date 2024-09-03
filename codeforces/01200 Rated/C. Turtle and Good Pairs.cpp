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
    string s;
    cin >> s;

    s = ' ' + s;

    map<char, lli> m;

    f(i,1,n+1){
        m[s[i]]++;
    }

    multiset<pair<lli, char>> st;

    for(auto &i : m){
        st.insert({i.second, i.first});
    }

    while(st.size()> 1){

        auto it1 = *st.rbegin();
        st.erase(st.find(*st.rbegin()));
        auto it2 = *st.rbegin();
        st.erase(st.find(*st.rbegin()));

        cout << it1.second;
        it1.first--;
        cout << it2.second;
        it2.first--;

        if(it1.first > 0){
            st.insert(it1);
        }
        if(it2.first > 0){
            st.insert(it2);
        }
    }

    if(!st.empty()){
        f(i, 0, (*st.rbegin()).first){
            cout << (*st.rbegin()).second;
        }
    }

    cout << endl;
}
int main() {
    lli t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}