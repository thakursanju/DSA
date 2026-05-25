class Solution {
int solve(vector<int>& prices, vector<vector<int>> & dp,int i,int j,int k){
    if(i>=prices.size()){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int profit=0;
    if (j){
        profit=max(-prices[i]+solve(prices,dp,i+1,0,k),solve(prices,dp,i+1,1,k));
    }
    else{
        profit=max(prices[i]+solve(prices,dp,i+1,1,k)-k,solve(prices,dp,i+1,0,k));
    }
    return dp[i][j]=profit;
}
public:
    int maxProfit(vector<int>& prices,int fee) {
        int n=prices.size();
         vector<vector<int>> dp(n,vector<int>(2,-1));
        return solve(prices,dp,0,1,fee);
    }
};