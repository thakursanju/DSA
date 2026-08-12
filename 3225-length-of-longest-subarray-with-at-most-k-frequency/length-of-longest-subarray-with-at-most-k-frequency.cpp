class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n=nums.size();
        int l=0;
        int m=0;
        unordered_map <int,int> mp;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
            while(mp[nums[i]]>k){
                mp[nums[l]]--;
                l++;
            }
            m=max(m,i-l+1);
        }
        return m;
    }
};