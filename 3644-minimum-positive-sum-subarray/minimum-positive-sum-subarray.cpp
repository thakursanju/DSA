class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();
        bool found = false;
        int mini = INT_MAX;

        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = i; j < n; j++) {
                sum += nums[j];
                                int len = j - i + 1;

                if (len >= l && len <= r && sum > 0) {
                    mini = min(mini, sum);
                    found = true;
                }
            }
        }

        if (found) {
            return mini;
        } else {
            return -1;
        }
    }
};
