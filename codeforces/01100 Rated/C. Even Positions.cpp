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
    int op = 0;

    f(i,1,n+1){
        char c = s[i];


        if(c == '('){
            op++;
        }else if(c == ')'){
            op--;
        }

        else{
            if(op>0){
                s[i] = ')';
                op--;
            }else if(op == 0){
                s[i] = '(';
                op++;
            }
        }
    }

    stack<int> st;
    lli cost = 0;

    f(i,1,n+1){
        if(s[i] == '('){
            st.push(i);
        }
        else{
            int open = st.top();

            st.pop();

            cost += abs(i - open);
        }
    }
    cout << cost << endl;
}
int main() {
    lli t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}