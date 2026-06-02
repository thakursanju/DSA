class Solution {

int solve(int i,int pre,vector<vector<int>> &dp,vector<int> &nums,int n){
    if(i==n) return 0;
    if(dp[i][pre+1]!=-1){
        return dp[i][pre+1];
    }
    int nt=0+solve(i+1,pre,dp,nums,n);
    if(pre==-1||nums[i]>nums[pre]){
        nt=max(nt,1+solve(i+1,i,dp,nums,n));
    }
    return dp[i][pre+1]=nt;
}
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return solve(0,-1,dp,nums,n);
    
    }
};