class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long, int> freq;
        int mx = INT_MIN;

        // build frequency map
        for (int num : nums) {
            freq[(long long)num]++;
        }

        // special case for 1
        if (freq.count(1)) {
            int ones = freq[1];
            mx = max(mx, (ones % 2 == 0) ? (ones - 1) : ones);
        }

        // process power chains
        for (auto &it : freq) {
            long long key = it.first;

            if (key == 1) continue;

            long long next = key;
            int len = 0;

            while (freq.count(next)) {
                if (freq[next] >= 2) {
                    len++;
                } else {
                    len++;
                    break;
                }

                // overflow safety
                if (next > (long long)1e9 / next) break;

                next *= next;
            }

            mx = max(mx, 2 * len - 1);
        }

        return mx;
    }
};