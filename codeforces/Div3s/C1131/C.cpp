#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    long long total = 0;
    for (int &v : a) {
        cin >> v;
        total += v;
    }

    vector<int> pre(n + 1, 0);
    for (int i = 0; i < n; i++) pre[i + 1] = pre[i] + (a[i] >= 2);
    auto hasBig = [&](int l, int r) { return l <= r && pre[r + 1] - pre[l] > 0; };

    long long best = -1;
    for (int j = 0; j < n; j++) {
        long long lossLeft, lossRight;

        if (j == 0) lossLeft = 0;
        else if (hasBig(1, j - 1)) lossLeft = 1;
        else if (a[0] >= 2) lossLeft = j;
        else continue;

        if (j == n - 1) lossRight = 0;
        else if (hasBig(j + 1, n - 2)) lossRight = 1;
        else if (a[n - 1] >= 2) lossRight = n - 1 - j;
        else continue;

        best = max(best, total - lossLeft - lossRight);
    }
    cout << best << '\n';
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
