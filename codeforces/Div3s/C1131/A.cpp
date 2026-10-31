/*
A:- It was a pretty straightforward problem. Since multiplication is commutative, the order of the
letters doesn't matter at all, only the count of every letter matters. So you just need to maintain a
freq array of size 26, do +1 for every character of p (numerator) and -1 for every character of q
(denominator). Cancelling a variable is basically just this subtraction.

After that just check the freq array. 's', 'i' and 'x' should have exactly 1 left and every other
letter should have exactly 0. If something is negative then that letter is stuck in the denominator,
and if something extra is left then the numerator is not exactly "six". In both the cases it's a NO.

Time complexity:- O(n + m)
*/

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
