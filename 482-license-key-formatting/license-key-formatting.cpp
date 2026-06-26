class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        string t;

        for (char c : s) {
            if (c != '-')
                t += toupper(c);
        }

        string ans;
        int cnt = 0;

        for (int i = t.size() - 1; i >= 0; i--) {
            if (cnt == k) {
                ans += '-';
                cnt = 0;
            }
            ans += t[i];
            cnt++;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};