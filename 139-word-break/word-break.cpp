class Solution {
private:
   bool solve(int k,vector<int>& dp,string s,unordered_set<string> &wd){
    if(k==s.size()){
        return true;
    }
    if(dp[k]!=-1) return dp[k];
    for(int i=1;i+k<=s.size();i++){
        string x=s.substr(k,i);
        if(wd.find(x)!=wd.end()&& solve(k+i,dp,s,wd)){
            return dp[k]=true;
        }
    }
    return dp[k]=false;
   }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wd(wordDict.begin(), wordDict.end());
        int n=s.size();
        vector<int> dp(n,-1);
        return solve(0,dp,s,wd);  
    }
};