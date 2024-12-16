#include <iostream>
#include <vector>
using namespace std;

#define lli long long int

void solve()
{
    lli n;
    cin >> n;

    vector<lli> r(n);
    for (lli i = 0; i < n; i++)
    {
        cin >> r[i];
    }

    vector<lli> p(n, 1);
    const lli MAX_ITERATIONS = 1e6; // Safety limit

    auto nextDistribution = [&](const vector<lli> &p)
    {
        vector<lli> np(n, 0);
        for (lli i = 0; i < n; i++)
        {
            if (p[i] > 0)
            {
                np[r[i]]++;
            }
        }
        for (lli i = 0; i < n; i++)
        {
            if (np[i] > 1)
            {
                np[i] = 1;
            }
        }
        return np;
    };

    vector<lli> slow = p, fast = p;
    lli year = 1;

    while (year <= MAX_ITERATIONS)
    {
        slow = nextDistribution(slow);                   // Move slow pointer one step
        fast = nextDistribution(nextDistribution(fast)); // Move fast pointer two steps

        if (slow == fast)
        { // Cycle detected
            lli stableYear = year;
            vector<lli> temp = nextDistribution(slow);
            while (temp != slow)
            {
                temp = nextDistribution(temp);
                stableYear++;
            }
            cout << stableYear << endl;
            return;
        }

        year++;
    }
