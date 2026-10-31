#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<long long> b(n);
    for (int i = 0; i < n; i++) {
        long long v;
        cin >> v;
        b[i] = (i % 2 == 0) ? v : -v;
    }

    sort(b.rbegin(), b.rend());
    int plusCount = (n + 1) / 2;

    long long sum = 0;
    for (int i = 0; i < n; i++) sum += (i < plusCount) ? b[i] : -b[i];

    cout << sum << '\n';
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
