class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> ans(k, 0);
        vector<long long> dp(k, 0);

        for (int x : nums) {
            vector<long long> newdp(k, 0);

            // Start a new subarray with x
            newdp[x % k]++;

            // Extend previous subarrays
            for (int r = 0; r < k; r++) {
                if (dp[r] > 0) {
                    int nr = (r * (x % k)) % k;
                    newdp[nr] += dp[r];
                }
            }

            // Add all subarrays ending here
            for (int r = 0; r < k; r++) {
                ans[r] += newdp[r];
            }

            dp = newdp;
        }

        return ans;
    }
};