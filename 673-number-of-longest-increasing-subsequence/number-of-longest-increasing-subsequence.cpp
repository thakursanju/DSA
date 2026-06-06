class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,1),cnt(n,1);
        int maxi=1;
        for(int i=1;i<n;i++){
            for(int p=0;p<i;p++){
                if(nums[i]>nums[p]&&1+dp[p]>dp[i]){
                    dp[i]=1+dp[p];
                    cnt[i]=cnt[p];
                }
                else if (nums[i]>nums[p]&&1+dp[p]==dp[i]){
                    cnt[i]+=cnt[p];
                }
            }
            if(dp[i]>maxi){
                maxi=dp[i];
            }
        }
        int c=0;
        for(int i=0;i<n;i++){
            if(dp[i]==maxi){
                c+=cnt[i];
            }
        }
        return c;
        
    }
};