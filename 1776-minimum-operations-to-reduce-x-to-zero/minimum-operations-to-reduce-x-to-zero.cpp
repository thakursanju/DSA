class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();

        long long sum = 0;
        for (int num : nums) {
            sum += num;
        }

        long long target = sum - x;

        // We need to remove everything
        if (target < 0)
            return -1;

        // If target = 0, remove all elements
        if (target == 0)
            return n;

        int left = 0;
        long long curr = 0;
        int maxLen = -1;

        for (int right = 0; right < n; right++) {
            curr += nums[right];

            while (curr > target && left <= right) {
                curr -= nums[left];
                left++;
            }

            if (curr == target) {
                maxLen = max(maxLen, right - left + 1);
            }
        }

        if (maxLen == -1)
            return -1;

        return n - maxLen;
    }
};