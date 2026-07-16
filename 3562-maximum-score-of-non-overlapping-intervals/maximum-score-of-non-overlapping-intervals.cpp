class Solution {
public:
    struct Node {
        long long sum;
        vector<int> idx;

        Node(long long s = 0, vector<int> v = {}) {
            sum = s;
            idx = v;
        }
    };

    static bool better(const Node &a, const Node &b) {
        if (a.sum != b.sum)
            return a.sum > b.sum;
        return a.idx < b.idx;
    }

    vector<int> maximumWeight(vector<vector<int>>& intervals) {

        int n = intervals.size();

        vector<array<long long,4>> arr;

        for (int i = 0; i < n; i++) {
            arr.push_back({
                intervals[i][0],
                intervals[i][1],
                intervals[i][2],
                i
            });
        }

        sort(arr.begin(), arr.end(),
             [](auto &a, auto &b) {
                 if (a[1] == b[1]) return a[0] < b[0];
                 return a[1] < b[1];
             });

        vector<long long> ends(n);

        for (int i = 0; i < n; i++)
            ends[i] = arr[i][1];

        vector<int> pre(n);

        for (int i = 0; i < n; i++) {

            int p = lower_bound(
                        ends.begin(),
                        ends.end(),
                        arr[i][0]) - ends.begin();

            pre[i] = p - 1;
        }

        vector<vector<Node>> dp(n + 1,
                                vector<Node>(5));

        for (int i = 1; i <= n; i++) {

            auto cur = arr[i - 1];

            for (int k = 0; k <= 4; k++)
                dp[i][k] = dp[i - 1][k];

            for (int k = 1; k <= 4; k++) {

                Node take;

                if (pre[i - 1] == -1)
                    take = dp[0][k - 1];
                else
                    take = dp[pre[i - 1] + 1][k - 1];

                take.sum += cur[2];
                take.idx.push_back(cur[3]);

                sort(take.idx.begin(), take.idx.end());

                if (better(take, dp[i][k]))
                    dp[i][k] = take;
            }
        }

        Node ans;

        for (int k = 0; k <= 4; k++)
            if (better(dp[n][k], ans))
                ans = dp[n][k];

        return ans.idx;
    }
};