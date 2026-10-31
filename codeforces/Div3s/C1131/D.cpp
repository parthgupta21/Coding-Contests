/*
D:- The trick here is to look at the operation differently. Locking k elements and moving the rest by
+1 is the same as moving only those k locked elements by -1, because we only care about everything
being equal and not about the final value. So every operation is basically "pick some elements, move
them by 1 and pay 1 for every element you picked".

After that the problem became pretty standard. Every element has to move |a[i] - T| steps where T is
the final value, and the sum of |a[i] - T| is minimum when T is the median. So minimum cost = sum of
|a[i] - median|.

For the number of operations, with the minimum cost nothing can ever move in the wrong direction, so
the ups and the downs are separate operations. Ups need (median - min) operations and downs need
(max - median), which adds up to max - min.

Use long long, the cost can go upto 4e14.

Time complexity:- O(n log n)
*/

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
