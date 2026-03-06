class Solution {
private:
int f(int i,int j,vector<int>& prices,vector<vector<vector<int>>>& dp,int n,int x){
    if(i==n || x==0) return 0;

    if(dp[i][j][x]!=-1) return dp[i][j][x];

    int pf=0;

    if(j){
        pf=max(-prices[i]+f(i+1,0,prices,dp,n,x),
               f(i+1,1,prices,dp,n,x));
    }
    else{
        pf=max(prices[i]+f(i+1,1,prices,dp,n,x-1),
               f(i+1,0,prices,dp,n,x));
    }

    return dp[i][j][x]=pf;
}

public:
int maxProfit(vector<int>& prices) {
    int n=prices.size();
    vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
    return f(0,1,prices,dp,n,2);
}
};