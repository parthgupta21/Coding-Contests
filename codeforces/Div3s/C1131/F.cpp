#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;
const int MAXN = 4005;
long long fact[MAXN], inv_fact[MAXN];

long long power(long long base, long long exp) {
    long long result = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp & 1) result = result * base % MOD;
        base = base * base % MOD;
        exp >>= 1;
    }
    return result;
}

long long nCr(int n, int r) {
    if (r < 0 || r > n) return 0;
    return fact[n] * inv_fact[r] % MOD * inv_fact[n - r] % MOD;
}

long long spaceOptimization(int n, int m) {
    int top = m + 2, K = min(n - 1, m);
    vector<long long> prev(top + 1, 0), cur(top + 1, 0), prefix(top + 1, 0);
    prev[2] = 1;

    long long answer = prev[top] * nCr(n, 1) % MOD;
    for (int k = 1; k <= K; k++) {
        for (int v = 1; v <= top; v++) prefix[v] = (prefix[v - 1] + prev[v]) % MOD;

        for (int v = 2; v <= top; v++) {
            cur[v] = (prefix[v - 1] - prefix[v / 2] + MOD) % MOD;
        }
        prev = cur;
        answer = (answer + prev[top] * nCr(n, k + 1)) % MOD;
    }
    return answer;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    fact[0] = 1;
    for (int i = 1; i < MAXN; i++) fact[i] = fact[i - 1] * i % MOD;
    inv_fact[MAXN - 1] = power(fact[MAXN - 1], MOD - 2);
    for (int i = MAXN - 1; i > 0; i--) inv_fact[i - 1] = inv_fact[i] * i % MOD;

    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        cout << spaceOptimization(n, m) << '\n';
    }

    return 0;
}
