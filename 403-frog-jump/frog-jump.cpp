class Solution {
public:
    unordered_map<long long, bool> dp;
    unordered_map<int, int> pos;

    bool dfs(vector<int>& stones, int i, int k) {
        if (i == stones.size() - 1)
            return true;

        long long key = (1LL * i << 32) | k;
        if (dp.count(key))
            return dp[key];

        for (int jump = k - 1; jump <= k + 1; jump++) {
            if (jump <= 0) continue;

            int next = stones[i] + jump;

            if (pos.count(next)) {
                if (dfs(stones, pos[next], jump))
                    return dp[key] = true;
            }
        }

        return dp[key] = false;
    }

    bool canCross(vector<int>& stones) {
        for (int i = 0; i < stones.size(); i++)
            pos[stones[i]] = i;

        return dfs(stones, 0, 0);
    }
};