class Solution {
public:
    int findSubstringInWraproundString(string s) {
        vector<int> dp(26, 0);
        int len = 0;

        for (int i = 0; i < s.size(); i++) {
            if (i > 0 && ((s[i] - s[i - 1] + 26) % 26 == 1))
                len++;
            else
                len = 1;

            dp[s[i] - 'a'] = max(dp[s[i] - 'a'], len);
        }

        int ans = 0;
        for (int x : dp)
            ans += x;

        return ans;
    }
};