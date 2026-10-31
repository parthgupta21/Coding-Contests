#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (long long &v : a) cin >> v;

    sort(a.begin(), a.end());
    long long median = a[n / 2];

    long long cost = 0;
    for (long long v : a) cost += llabs(v - median);

    cout << cost << ' ' << a[n - 1] - a[0] << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}
