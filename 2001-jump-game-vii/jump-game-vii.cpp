class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n=s.size();
        vector<bool> dp(n,0);
        if(s[n-1]=='1'){
            return 0;
        }
        dp[0]=1;
        int c=0;
        for(int j=0;j<n;j++){
            if(j>=minJump){
                if(dp[j-minJump]){
                    c++;
                }
            }
            if(j>maxJump){
                if(dp[j-maxJump-1]){
                    c--;
                }
            }
            if(s[j]=='0'&&c>0){
                dp[j]=1;
            }
        }
        return dp[n-1];
        
    }
};