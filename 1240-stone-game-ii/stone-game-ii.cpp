class Solution {
private:
   int solve(int i,int M,vector<int> & piles,vector<vector<int>> &dp,vector<int> & suffix){
    if(i>=piles.size()) return 0;
    if(dp[i][M]!=-1) return dp[i][M];
    if(i+2*M>=piles.size()){
        return suffix[i];
    }
    int ans=0;
    for(int i1=1;i1<=2*M;i1++){
        int take=solve(i+i1,max(i1,M),piles,dp,suffix);
        ans=max(ans,suffix[i]-take);
    }
    return dp[i][M]=ans;
   }
public:
    int stoneGameII(vector<int>& piles) {
        int n=piles.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));// maxi /
        vector<int> suffix(n+1,0);
        suffix[n-1]=piles[n-1];
        for(int i=n-2;i>=0;i--){
            suffix[i]=suffix[i+1]+piles[i];
        }
        return solve(0,1,piles,dp,suffix);
    }
};