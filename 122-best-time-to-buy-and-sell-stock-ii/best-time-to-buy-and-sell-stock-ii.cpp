class Solution {
private :
int f(int i,int j,vector<int>& prices,vector<vector<int>>& dp,int n){
    if(i==n){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int pf=0;
    if(j){
        pf=max(-prices[i]+f(i+1,0,prices,dp,n),0+f(i+1,1,prices,dp,n));
    }
    else{
        pf=max(prices[i]+f(i+1,1,prices,dp,n),0+f(i+1,0,prices,dp,n));
    }
    return dp[i][j]=pf;

}
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return f(0,1,prices,dp,n);
        
    }
};