class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        if (p.size() > s.size()) return ans;

        vector<int> cntP(26, 0), cntS(26, 0);

        for (char c : p)
            cntP[c - 'a']++;

        int k = p.size();

        for (int i = 0; i < s.size(); i++) {
            cntS[s[i] - 'a']++;

            if (i >= k)
                cntS[s[i - k] - 'a']--;

            if (cntS == cntP)
                ans.push_back(i - k + 1);
        }

        return ans;
    }
};