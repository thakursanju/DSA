#include <bits/stdc++.h>
using namespace std;

struct SegmentTree {
    int n;
    vector<int> sum, mn, mx;

    SegmentTree(int n) {
        this->n = n;
        sum.assign(4 * n, 0);
        mn.assign(4 * n, 0);
        mx.assign(4 * n, 0);
    }

    void pull(int node) {
        int l = node * 2, r = node * 2 + 1;
        sum[node] = sum[l] + sum[r];
        mn[node] = min(mn[l], sum[l] + mn[r]);
        mx[node] = max(mx[l], sum[l] + mx[r]);
    }

    void update(int node, int l, int r, int idx, int val) {
        if (l == r) {
            sum[node] = val;
            mn[node] = val;
            mx[node] = val;
            return;
        }

        int mid = (l + r) / 2;
        if (idx <= mid)
            update(node * 2, l, mid, idx, val);
        else
            update(node * 2 + 1, mid + 1, r, idx, val);

        pull(node);
    }

    void update(int idx, int val) {
        update(1, 0, n - 1, idx, val);
    }

    int findRightPre(int node, int l, int r, int target, int sumBefore) {
        if (!(mn[node] + sumBefore <= target &&
              target <= mx[node] + sumBefore))
            return -1;

        if (l == r)
            return l;

        int mid = (l + r) / 2;

        // Try right side first (to maximize length)
        int right = findRightPre(node * 2 + 1, mid + 1, r,
                                 target, sumBefore + sum[node * 2]);
        if (right != -1)
            return right;

        return findRightPre(node * 2, l, mid, target, sumBefore);
    }

    int findRightPre(int target) {
        return findRightPre(1, 0, n - 1, target, 0);
    }
};

class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        SegmentTree seg(n);

        unordered_map<int, int> lastPos;
        int ans = 0;

        for (int l = n - 1; l >= 0; --l) {
            int num = nums[l];

            // remove previous occurrence
            if (lastPos.count(num))
                seg.update(lastPos[num], 0);

            lastPos[num] = l;

            // even = +1, odd = -1
            seg.update(l, (num % 2 == 0) ? 1 : -1);

            int r = seg.findRightPre(0);

            if (r >= l)
                ans = max(ans, r - l + 1);
        }

        return ans;
    }
};
