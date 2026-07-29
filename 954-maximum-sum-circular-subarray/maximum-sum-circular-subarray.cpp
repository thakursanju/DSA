class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {

        int total = 0;

        int curMax = 0, maxSum = INT_MIN;
        int curMin = 0, minSum = INT_MAX;

        for (int x : nums) {

            total += x;

            // Maximum subarray sum (Kadane)
            curMax = max(x, curMax + x);
            maxSum = max(maxSum, curMax);

            // Minimum subarray sum (Reverse Kadane)
            curMin = min(x, curMin + x);
            minSum = min(minSum, curMin);
        }

        // All numbers are negative
        if (maxSum < 0)
            return maxSum;

        return max(maxSum, total - minSum);
    }
};