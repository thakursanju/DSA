class Solution {
public:
    using ll = long long;

    vector<vector<int>> mx, mn;
    vector<int> lg;

    long long maxTotalValue(vector<int>& nums, int k) {
        int n = nums.size();

        buildSparse(nums);

        auto getValue = [&](int l, int r) -> long long {
            int len = r - l + 1;
            int p = lg[len];

            int mxv = max(mx[p][l], mx[p][r - (1 << p) + 1]);
            int mnv = min(mn[p][l], mn[p][r - (1 << p) + 1]);

            return 1LL * mxv - mnv;
        };

        struct Node {
            long long val;
            int l, r;

            bool operator<(const Node& other) const {
                return val < other.val; // max heap
            }
        };

        priority_queue<Node> pq;

        for (int l = 0; l < n; l++) {
            pq.push({getValue(l, n - 1), l, n - 1});
        }

        long long ans = 0;

        while (k--) {
            auto cur = pq.top();
            pq.pop();

            ans += cur.val;

            if (cur.r > cur.l) {
                int nr = cur.r - 1;
                pq.push({getValue(cur.l, nr), cur.l, nr});
            }
        }

        return ans;
    }

    void buildSparse(vector<int>& nums) {
        int n = nums.size();

        lg.assign(n + 1, 0);
        for (int i = 2; i <= n; i++)
            lg[i] = lg[i / 2] + 1;

        int K = lg[n] + 1;

        mx.assign(K, vector<int>(n));
        mn.assign(K, vector<int>(n));

        for (int i = 0; i < n; i++) {
            mx[0][i] = nums[i];
            mn[0][i] = nums[i];
        }

        for (int j = 1; j < K; j++) {
            int len = 1 << j;

            for (int i = 0; i + len <= n; i++) {
                mx[j][i] = max(mx[j - 1][i],
                               mx[j - 1][i + (len >> 1)]);

                mn[j][i] = min(mn[j - 1][i],
                               mn[j - 1][i + (len >> 1)]);
            }
        }
    }
};