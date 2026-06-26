class Solution {
public:
    bool canSplit(vector<int>& nums, int k, long long mx) {
        int cnt = 1;
        long long sum = 0;

        for (int x : nums) {
            if (sum + x <= mx) {
                sum += x;
            } else {
                cnt++;
                sum = x;
            }
        }

        return cnt <= k;
    }

    int splitArray(vector<int>& nums, int k) {
        long long lo = *max_element(nums.begin(), nums.end());
        long long hi = 0;

        for (int x : nums)
            hi += x;

        while (lo < hi) {
            long long mid = lo + (hi - lo) / 2;

            if (canSplit(nums, k, mid))
                hi = mid;
            else
                lo = mid + 1;
        }

        return lo;
    }
};