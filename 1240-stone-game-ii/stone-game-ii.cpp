class Solution {
private:
   int solve(int i,int M,vector<int>& piles,vector<vector<int>>& dp,int n,vector<int>& sufix){
    if(i>=n) return 0;
    if(dp[i][M]!=-1) return dp[i][M];
    // fisrt alice m=1 always 
    if(i+2*M>=n){
        return sufix[i];
    }
    int ans=0;
    for(int k=1;k<=2*M;k++){
        int take=solve(i+k,max(k,M),piles,dp,n,sufix);
        ans=max(ans,sufix[i]-take);
    }

return dp[i][M]=ans;
    }
   
public:
    int stoneGameII(vector<int>& piles) {
        int n=piles.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        vector<int> sufix(n+1,0);
        sufix[n-1] = piles[n-1];
        for(int i=n-2;i>=0;i--){
            sufix[i]=sufix[i+1]+piles[i];
        }
        return solve(0,1,piles,dp,n,sufix);

        
    }
};