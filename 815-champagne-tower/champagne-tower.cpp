class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<double> dp(query_row + 2, 0.0);
        dp[0] = (double)poured;

        for (int r = 0; r < query_row; r++) {
            vector<double> nxt(query_row + 2, 0.0);
            for (int j = 0; j <= r; j++) {
                double excess = dp[j] - 1.0;
                if (excess > 0.0) {
                    double half = excess / 2.0;
                    nxt[j] += half;       // left glass
                    nxt[j + 1] += half;   // right glass
                }
            }
            dp = nxt;
        }

        return min(1.0, dp[query_glass]);
    }
};
