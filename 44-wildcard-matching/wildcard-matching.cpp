class Solution {
private:
    bool f(int i ,int j ,vector<vector<int>> & dp,string &s,string &p){
        if(i<0&&j<0) return 1;
        if(j<0&&i>=0) return 0;
        if(i<0&&j>=0){
            for(int o=0;o<j+1;o++){
                if(p[o]!='*'){
                    return 0;
                }
            }
                return 1;

            
        }
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==p[j]||p[j]=='?'){
             return dp[i][j]=f(i-1,j-1,dp,s,p);

        }
        if(p[j]=='*'){
            return dp[i][j]=f(i-1,j,dp,s,p)||f(i,j-1,dp,s,p);
        }
        
        return dp[i][j]=0;

    }
public:
    bool isMatch(string s, string p) {
        int n=s.size();
        int m=p.size();
        vector<vector<int> > dp(n,vector<int>(m,-1));
        return f(n-1,m-1,dp,s,p);
        
    }
};