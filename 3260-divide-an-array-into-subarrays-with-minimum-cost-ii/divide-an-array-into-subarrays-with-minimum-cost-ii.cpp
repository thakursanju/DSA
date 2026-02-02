#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        const int n = (int)nums.size();
        const int need = k - 1;                     // how many starts after the first one
        const int maxWindow = dist + 1;             // maximal allowed length of the window

        // multisets for the two halves of the current window
        multiset<long long> small;   // holds the need smallest elements
        multiset<long long> big;     // all other elements
        long long sumSmall = 0;      // sum of elements in 'small'

        auto rebalance = [&](void) {
            // make |small| == need   (or = current window size if it is smaller)
            while ((int)small.size() > need) {
                auto it = prev(small.end());          // largest in small
                long long val = *it;
                sumSmall -= val;
                big.insert(val);
                small.erase(it);
            }
            while ((int)small.size() < need && !big.empty()) {
                auto it = big.begin();                // smallest in big
                long long val = *it;
                sumSmall += val;
                small.insert(val);
                big.erase(it);
            }
        };

        auto add = [&](long long x) {
            if (small.empty() || x <= *prev(small.end())) {
                small.insert(x);
                sumSmall += x;
            } else {
                big.insert(x);
            }
            rebalance();
        };

        auto remove = [&](long long x) {
            auto it = small.find(x);
            if (it != small.end()) {
                sumSmall -= x;
                small.erase(it);
            } else {
                it = big.find(x);
                // x is guaranteed to be present
                big.erase(it);
            }
            rebalance();
        };

        // initialise first window L = 1
        int L = 1;
        int R = min(L + dist, n - 1);
        for (int i = L; i <= R; ++i) add(nums[i]);

        long long best = LLONG_MAX;                 // minimal sum of (k-1) chosen numbers
        int curL = L, curR = R;

        while (curL <= n - 1) {
            int curSize = curR - curL + 1;
            if (curSize >= need) {
                best = min(best, sumSmall);
            }

            // slide window one step to the right
            remove(nums[curL]);                     // element leaving
            ++curL;
            int newR = min(curL + dist, n - 1);
            if (newR > curR) {
                add(nums[newR]);                     // new element entering
                curR = newR;
            }
        }

        // the answer always exists because dist ≥ k‑2  →  window size ≥ need
        return (long long)nums[0] + best;
    }
};