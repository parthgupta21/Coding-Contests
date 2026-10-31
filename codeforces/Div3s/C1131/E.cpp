/*
E:- A classic "find what doesn't change" problem. I just took [x, y, z] and tracked x on paper, every
time it moves one step its sign flips. So the sign only depends on how far it has moved.

So flip the sign of every second element and make a new array b. Now the operation is just a plain
adjacent swap in b, which means b can be rearranged in any order we want.

Sum of a = b1 - b2 + b3 - b4 ... so there are ceil(n/2) plus slots and floor(n/2) minus slots. Sort b
in descending order, put the biggest values on the plus slots and the rest on the minus slots.

Time complexity:- O(n log n)
*/

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
