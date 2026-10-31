/*
B:- A little tricky as you need to realize that Bob doesn't need to mix his moves at all. If Bob plays
the same move in every round then the order of Alice's moves doesn't matter, every round looks the
same to him.

All Paper -> Bob's wins - losses = x - y (beats Rock, loses to Scissors)
All Rock -> y - z
All Scissors -> z - x

These three add up to 0, so at least one of them has to be >= 0. Just pick that move and print it
(x + y + z) times.

Time complexity:- O(x + y + z)
*/

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
