/*
C:- This one took some time. You need to realize two things, firstly mass is only lost when you split
the leftmost or the rightmost core (one part falls off the edge), splitting a middle core keeps all
the mass. Secondly, you can always make the lost part exactly 1.

So fix the core j which survives at the end and look at both sides separately. For the left side:
-> no cores on the left: loss = 0
-> some core between 2 and j-1 has mass >= 2: split it first and keep splitting outwards (the
   neighbours always become >= 2), only core 1 falls off the edge at the end, so loss = 1
-> all of them are 1 but core 1 is >= 2: every removal happens at the edge, so loss = j - 1
-> everything is 1: nothing can ever move, so j is not possible
Same thing for the right side.

Answer = max over j of (total - leftLoss - rightLoss), or -1 if no j works. I used a prefix count of
cores with mass >= 2 so that every range check is O(1).

Time complexity:- O(n)
*/

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
