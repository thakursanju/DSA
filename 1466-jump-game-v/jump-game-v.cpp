class Solution {
int solve(vector<int>& arr,vector<int> & dp,int d,int i){
    
    if(dp[i]!=-1){
        return dp[i];
    }
    int count=1;
    int n=arr.size();
    for(int j=i-1;j>=max(0,i-d);j--){
        if(arr[j]>=arr[i]) break;
        count=max(count,1+solve(arr,dp,d,j));
    }
    for(int j=i+1;j<=min(n-1,i+d);j++){
        if(arr[j]>=arr[i]) break;
        count=max(count,1+solve(arr,dp,d,j));
    }    
    return dp[i]=count;

}
public:
    int maxJumps(vector<int>& arr, int d) {
        int n=arr.size();
        vector<int> dp(n+1,-1);
        int ans=0;
        for(int i=n-1;i>=0;i--){
         ans = max(ans,solve(arr,dp,d,i));
        }
        return ans;
        
    }
};