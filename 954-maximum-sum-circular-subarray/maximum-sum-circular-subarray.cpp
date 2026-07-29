class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();

        vector<int> arr(2 * n);
        for (int i = 0; i < n; i++) {
            arr[i] = nums[i];
            arr[i + n] = nums[i];
        }

        vector<long long> prefix(2 * n + 1, 0);
        for (int i = 0; i < 2 * n; i++)
            prefix[i + 1] = prefix[i] + arr[i];

        deque<int> dq;
        dq.push_back(0);

        long long ans = LLONG_MIN;

        for (int i = 1; i <= 2 * n; i++) {

            while (!dq.empty() && dq.front() < i - n)
                dq.pop_front();

            if (!dq.empty())
                ans = max(ans, prefix[i] - prefix[dq.front()]);

            while (!dq.empty() && prefix[dq.back()] >= prefix[i])
                dq.pop_back();

            dq.push_back(i);
        }

        return (int)ans;
    }
};