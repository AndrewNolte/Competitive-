
#include <iostream>
#include <vector>
#include <stdio.h>
#include <math.h>
#include <utility>
#include <queue>
#include <stack>
#include <unordered_map>
#include <climits>

using namespace std;

uint64_t time(uint64_t ppl, uint64_t x, uint64_t k)
{
    return ((ppl) * (ppl - 1)) / 2 + floor(ppl / x) * k;
}

uint64_t solve(uint64_t n, uint64_t x, uint64_t k)
{

    double b = -.5;
    double est = -b + sqrt(b * b + 2 * n);
    uint64_t high = floor(est) + 1;

    b = -.5 + ((double)k) / ((double)x);
    est = -b + sqrt(b * b + 2 * n);
    uint64_t low = floor(est) - 1;

    while (low + 1 < high)
    {
        uint64_t mid = low + (high - low) / 2;
        if (time(mid, x, k) <= n)
        {
            low = mid;
        }
        else
        {
            high = mid;
        }
    }

    return low;
}

int main()
{
    int numCases;
    cin >> numCases;

    for (int test = 0; test < numCases; test++)
    {
        uint64_t n, x, k;
        cin >> n;
        cin >> x; //x = g
        cin >> k;

        cout << solve(n, x, k) << endl;
    }
}
