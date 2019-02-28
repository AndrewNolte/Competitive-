
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

uint64_t lines(uint64_t v, uint64_t k)
{
    uint64_t total = 0;
    double inner = (double)v;
    double kk = (double)k;
    while (inner != 0)
    {
        total += floor(inner);
        inner /= kk;
    }
    return total;
}
uint64_t solve(uint64_t n, uint64_t k)
{
    uint64_t low = 0;
    uint64_t high = n;

    while (low + 1 < high)
    {
        uint64_t mid = low + (high - low) / 2;
        if (lines(mid, k) < n)
        {
            low = mid;
        }
        else
        {
            high = mid;
        }
    }

    return high;
}

int main()
{
    uint64_t n, k;
    cin >> n;
    cin >> k;

    cout << solve(n, k);
}