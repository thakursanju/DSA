class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {

        vector<int> ans;

        int len = words[0].size();

        unordered_map<string, int> need;
        for (string &word : words)
            need[word]++;

        for (int offset = 0; offset < len; offset++) {

            unordered_map<string, int> window;
            int left = offset;
            int count = 0;

            for (int right = offset; right + len <= s.size(); right += len) {

                string word = s.substr(right, len);

                if (need.count(word)) {

                    window[word]++;
                    count++;

                    while (window[word] > need[word]) {
                        string leftWord = s.substr(left, len);
                        window[leftWord]--;
                        left += len;
                        count--;
                    }

                    if (count == words.size()) {
                        ans.push_back(left);

                        string leftWord = s.substr(left, len);
                        window[leftWord]--;
                        left += len;
                        count--;
                    }

                } else {
                    window.clear();
                    count = 0;
                    left = right + len;
                }
            }
        }

        return ans;
    }
};