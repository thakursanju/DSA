class Solution {
private:
   bool dr(int i,int j,const string &s,vector<vector<int>> &dp,int n ){
    if(j<0){
    return 0;
    }
    if(i==n){
        return j==0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    if(s[i]=='('){
        return dp[i][j]=dr(i+1,j+1,s,dp,n);
    }
    if (s[i]==')'){
        return dp[i][j]=dr(i+1,j-1,s,dp,n);
    }
    return dp[i][j]=dr(i+1,j+1,s,dp,n)||dr(i+1,j-1,s,dp,n)||dr(i + 1, j, s, dp, n);
   }
public:
    bool checkValidString(string s) {
        int n=s.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return dr(0,0,s,dp,n);
        
    }
};