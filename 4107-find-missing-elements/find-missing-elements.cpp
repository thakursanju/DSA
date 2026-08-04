class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int mn = nums.front();
        int mx = nums.back();
        vector<int> ans;
        int j = 0;
        for (int i = mn; i <= mx; i++) {
            if (j < nums.size() && nums[j] == i)
                j++;
            else
                ans.push_back(i);
        }
        return ans;
    }
};