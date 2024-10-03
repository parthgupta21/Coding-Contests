#include <bits/stdc++.h>
using namespace std;

#define int long long

void setIO()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int32_t main()
{
    setIO();

    int T;
    cin >> T;

    while (T--)
    {
        int n;
        cin >> n;

        vector<pair<int, int>> arr(n + 1);
        for (int i = 1; i <= n; i++)
        {
            cin >> arr[i].first;
            arr[i].second = i; // Storing the original index
        }

        // Sorting based on the value of arr[i].first
        sort(arr.begin() + 1, arr.end());

        vector<int> nxt(n + 1, 0), sum(n + 1, 0), ans(n + 1);

        for (int i = 1; i <= n; i++)
        {
            // Carry forward the previous nxt and sum if possible
            if (nxt[i - 1] >= i)
            {
                nxt[i] = nxt[i - 1];
                sum[i] = sum[i - 1];
            }
            else
            {
                // Otherwise, calculate new sum and extend nxt
                sum[i] = sum[i - 1] + arr[i].first;
                nxt[i] = i;
                // Extend nxt as far as the sum allows
                while (nxt[i] + 1 <= n && sum[i] >= arr[nxt[i] + 1].first)
                {
                    nxt[i]++;
                    sum[i] += arr[nxt[i]].first;
                }
            }
            ans[arr[i].second] = nxt[i];
        }

        // Output the result in the original order
        for (int i = 1; i <= n; i++)
        {
            cout << ans[i] - 1 << " ";
        }
        cout << endl;
    }
}
