class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {

        unordered_set<int> st;

        // Store all prefixes of arr1 numbers
        for (int num : arr1) {

            int x = num;
            vector<int> prefixes;

            while (x > 0) {
                prefixes.push_back(x);
                x /= 10;
            }

            for (int i = prefixes.size() - 1; i >= 0; i--) {
                st.insert(prefixes[i]);
            }
        }

        int ans = 0;

        // Check prefixes of arr2 numbers
        for (int num : arr2) {

            int x = num;

            while (x > 0) {

                if (st.count(x)) {
                    ans = max(ans, (int)to_string(x).size());
                }

                x /= 10;
            }
        }

        return ans;
    }
};