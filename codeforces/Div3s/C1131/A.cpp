#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    string p, q;
    cin >> n >> m >> p >> q;

    int cnt[26] = {0};
    for (char c : p) cnt[c - 'a']++;
    for (char c : q) cnt[c - 'a']--;

    bool ok = true;
    for (int c = 0; c < 26; c++) {
        int need = (c == 's' - 'a' || c == 'i' - 'a' || c == 'x' - 'a') ? 1 : 0;
        if (cnt[c] != need) ok = false;
    }
    cout << (ok ? "YES" : "NO") << '\n';
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
