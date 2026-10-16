
class Solution {
    static const int MOD = 1e9 + 7;

    struct Node {
        long long sum = 0;
        long long sq = 0;
        long long lazy = 0;
    };

    vector<Node> seg;
    int n;

    void apply(int node, int l, int r) {
        long long len = r - l + 1;
        long long s = seg[node].sum;

        seg[node].sq = (seg[node].sq + 2 * s + len) % MOD;
        seg[node].sum = (s + len) % MOD;
        seg[node].lazy++;
    }

    void push(int node, int l, int r) {
        if (seg[node].lazy == 0 || l == r)
            return;

        int mid = (l + r) / 2;
        long long lazy = seg[node].lazy;

        // Apply repeated increments using the general formula.
        auto updateChild = [&](int child, int left, int right) {
            long long len = right - left + 1;
            long long s = seg[child].sum;

            seg[child].sq =
                (seg[child].sq + 2 * lazy % MOD * s
                 + lazy * lazy % MOD * len) % MOD;

            seg[child].sum =
                (s + lazy * len) % MOD;

            seg[child].lazy += lazy;
        };

        updateChild(node * 2, l, mid);
        updateChild(node * 2 + 1, mid + 1, r);

        seg[node].lazy = 0;
    }

    void update(int node, int l, int r, int ql, int qr) {
        if (ql > r || qr < l)
            return;

        if (ql <= l && r <= qr) {
            apply(node, l, r);
            return;
        }

        push(node, l, r);

        int mid = (l + r) / 2;
        update(node * 2, l, mid, ql, qr);
        update(node * 2 + 1, mid + 1, r, ql, qr);

        seg[node].sum =
            (seg[node * 2].sum + seg[node * 2 + 1].sum) % MOD;

        seg[node].sq =
            (seg[node * 2].sq + seg[node * 2 + 1].sq) % MOD;
    }

public:
    int sumCounts(vector<int>& nums) {
        n = nums.size();
        seg.assign(4 * n + 5, Node());

        vector<int> last(100001, -1);
        long long ans = 0;

        for (int r = 0; r < n; r++) {
            int p = last[nums[r]];

            update(1, 0, n - 1, p + 1, r);

            last[nums[r]] = r;
            ans = (ans + seg[1].sq) % MOD;
        }

        return ans;
    }
};
