#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.length();
        vector<int> s_freq(26, 0);
        for (char c : s) s_freq[c - 'a']++;

        // Store prefix frequency counts of target
        vector<vector<int>> pref_freq(n + 1, vector<int>(26, 0));
        for (int i = 0; i < n; i++) {
            pref_freq[i + 1] = pref_freq[i];
            pref_freq[i + 1][target[i] - 'a']++;
        }

        // Try to match maximum possible prefix length k
        for (int k = n - 1; k >= 0; k--) {
            bool possible = true;
            for (int c = 0; c < 26; c++) {
                if (pref_freq[k][c] > s_freq[c]) {
                    possible = false;
                    break;
                }
            }

            if (possible) {
                vector<int> rem_freq(26, 0);
                for (int c = 0; c < 26; c++) {
                    rem_freq[c] = s_freq[c] - pref_freq[k][c];
                }

                int target_char = target[k] - 'a';
                for (int next_char = target_char + 1; next_char < 26; next_char++) {
                    if (rem_freq[next_char] > 0) {
                        string ans = target.substr(0, k);
                        ans += (char)('a' + next_char);
                        rem_freq[next_char]--;

                        // Append remaining characters in ascending order
                        for (int c = 0; c < 26; c++) {
                            ans.append(rem_freq[c], (char)('a' + c));
                        }
                        return ans;
                    }
                }
            }
        }

        return "";
    }
};