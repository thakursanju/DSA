class Solution {
private:
    int solve(int i, vector<int>& dp, vector<int>& stoneValue) {
        int n = stoneValue.size();
        if (i >= n) return 0;
        if (dp[i] != INT_MIN) return dp[i];
        int ans = INT_MIN;
        if (i < n) {
            ans = max(ans,
                      stoneValue[i] - solve(i + 1, dp, stoneValue));
        }
        if (i + 1 < n) {
            ans = max(ans,
                      stoneValue[i] + stoneValue[i + 1]
                      - solve(i + 2, dp, stoneValue));
        }
        if (i + 2 < n) {
            ans = max(ans,
                      stoneValue[i] + stoneValue[i + 1] + stoneValue[i + 2]
                      - solve(i + 3, dp, stoneValue));
        }
        return dp[i] = ans;
    }

public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> dp(n, INT_MIN);
        int diff = solve(0, dp, stoneValue);
        if (diff > 0) return "Alice";
        if (diff < 0) return "Bob";
        return "Tie";
    }
};