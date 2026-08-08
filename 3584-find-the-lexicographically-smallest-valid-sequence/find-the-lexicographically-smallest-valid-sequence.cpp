class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        // last[j] = position in word1 that matches word2[j]
        // while matching the suffix from right to left
        vector<int> last(m, -1);

        int i = n - 1;
        int j = m - 1;

        // Match word2 from right to left
        while (i >= 0 && j >= 0) {
            if (word1[i] == word2[j]) {
                last[j] = i;
                j--;
            }
            i--;
        }

        vector<int> ans;
        ans.reserve(m);

        bool canSkip = true;
        j = 0;

        // Scan word1 from left to right
        for (i = 0; i < n && j < m; i++) {

            // Characters match
            if (word1[i] == word2[j]) {
                ans.push_back(i);
                j++;
            }

            // Use the one allowed mismatch
            else if (canSkip && (j == m - 1 || i < last[j + 1])) {
                canSkip = false;
                ans.push_back(i);
                j++;
            }
        }

        // All characters matched
        if (j == m)
            return ans;

        return {};
    }
};