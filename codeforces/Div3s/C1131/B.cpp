#include <bits/stdc++.h>
using namespace std;

void solve() {
    int x, y, z;
    cin >> x >> y >> z;
    int n = x + y + z;

    char move;
    if (x - y >= 0) move = 'P';
    else if (y - z >= 0) move = 'R';
    else move = 'S';

    cout << string(n, move) << '\n';
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
