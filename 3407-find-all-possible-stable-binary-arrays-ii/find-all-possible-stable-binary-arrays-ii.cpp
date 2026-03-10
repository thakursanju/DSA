class Solution {
public:
    int numberOfStableArrays(int zero, int one, int limit) {
        const int MOD = 1e9 + 7;

        vector<vector<vector<long long>>> dp(
            zero + 1, vector<vector<long long>>(one + 1, vector<long long>(2, 0))
        );

        dp[0][0][0] = 1;
        dp[0][0][1] = 1;

        for (int z = 0; z <= zero; z++) {
            for (int o = 0; o <= one; o++) {

                if (z == 0 && o == 0) continue;

                // Case: last = 0
                if (z > 0) {

                    if (z <= limit) {
                        dp[z][o][0] = dp[z-1][o][1];

                        if (z > 1)
                            dp[z][o][0] = (dp[z][o][0] + dp[z-1][o][0]) % MOD;
                    }
                    else {
                        dp[z][o][0] = dp[z-1][o][1];

                        long long val = dp[z-1][o][0] - dp[z-1-limit][o][1];
                        val = (val % MOD + MOD) % MOD;

                        dp[z][o][0] = (dp[z][o][0] + val) % MOD;
                    }
                }

                // Case: last = 1
                if (o > 0) {

                    if (o <= limit) {
                        dp[z][o][1] = dp[z][o-1][0];

                        if (o > 1)
                            dp[z][o][1] = (dp[z][o][1] + dp[z][o-1][1]) % MOD;
                    }
                    else {
                        dp[z][o][1] = dp[z][o-1][0];

                        long long val = dp[z][o-1][1] - dp[z][o-1-limit][0];
                        val = (val % MOD + MOD) % MOD;

                        dp[z][o][1] = (dp[z][o][1] + val) % MOD;
                    }
                }
            }
        }

        return (dp[zero][one][0] + dp[zero][one][1]) % MOD;
    }
};