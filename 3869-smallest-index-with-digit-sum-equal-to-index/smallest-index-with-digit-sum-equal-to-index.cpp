class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        int n = nums.size();
        int ans = -1;

        for (int i = 0; i < n; i++) {
            int val = nums[i];
            int digitSum = 0;

            while (val > 0) {
                digitSum += val % 10;
                val /= 10;
            }

            if (digitSum == i) {
                ans = i;
                break;  // since we need smallest index
            }
        }

        return ans;
    }
};