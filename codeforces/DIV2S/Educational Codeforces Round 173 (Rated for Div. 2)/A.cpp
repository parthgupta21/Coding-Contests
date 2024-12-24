#include<bits/stdc++.h>

#define lli long long int
using namespace std;

void solve() {
    lli ni;
    cin >> ni;
    lli ci = 1;
    lli ans = 0;

    lli level = 0;

    while(ni > 3){
        ni = ni/4;
        level++;
        ans = pow(2, level);
        
    }

    if(ans > 0){
        cout << ans << endl;
    }else{
        cout << ci << endl;
    }
}
int main() {
    lli t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}