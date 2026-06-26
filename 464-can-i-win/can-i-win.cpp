class Solution {
public:
    unordered_map<int, bool> dp;

    bool dfs(int mask, int total, int mx) {
        if (total <= 0)
            return false;

        if (dp.count(mask))
            return dp[mask];

        for (int i = 1; i <= mx; i++) {
            if (!(mask & (1 << (i - 1)))) {
                if (!dfs(mask | (1 << (i - 1)), total - i, mx))
                    return dp[mask] = true;
            }
        }

        return dp[mask] = false;
    }

    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if (desiredTotal <= 0)
            return true;

        int sum = maxChoosableInteger * (maxChoosableInteger + 1) / 2;

        if (sum < desiredTotal)
            return false;

        return dfs(0, desiredTotal, maxChoosableInteger);
    }
};