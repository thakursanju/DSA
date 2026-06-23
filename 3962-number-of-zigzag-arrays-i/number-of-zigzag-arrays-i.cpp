constexpr int MOD = 1'000'000'007;

class Solution {
public:
    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;

        vector<int> up(m), down(m);

        // length = 2
        for (int j = 0; j < m; j++) {
            up[j] = j;           // values < j
            down[j] = m - 1 - j; // values > j
        }

        if (n == 2) {
            long long ans = 0;
            for (int j = 0; j < m; j++)
                ans = (ans + up[j] + down[j]) % MOD;
            return ans;
        }

        vector<int> prefUp(m + 1), prefDown(m + 1);

        for (int len = 3; len <= n; len++) {
            fill(prefUp.begin(), prefUp.end(), 0);
            fill(prefDown.begin(), prefDown.end(), 0);

            for (int j = 0; j < m; j++) {
                prefUp[j + 1] = (prefUp[j] + up[j]) % MOD;
                prefDown[j + 1] = (prefDown[j] + down[j]) % MOD;
            }

            vector<int> newUp(m), newDown(m);

            for (int j = 0; j < m; j++) {
                newUp[j] = prefDown[j];
                newDown[j] = (prefUp[m] - prefUp[j + 1] + MOD) % MOD;
            }

            up.swap(newUp);
            down.swap(newDown);
        }

        long long ans = 0;
        for (int j = 0; j < m; j++)
            ans = (ans + up[j] + down[j]) % MOD;

        return ans;
    }
};