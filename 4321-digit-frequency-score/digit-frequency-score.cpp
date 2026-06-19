class Solution {
public:
    int digitFrequencyScore(int n) {
        string s=to_string(n);
        vector<int> ans(10,0);
        for(int i=0;i<s.size();i++){
            ans[s[i]-'0']++;        
        }
        int sum=0;
        for(int i=0;i<ans.size();i++){
            if(ans[i]!=0){
                sum+=(i)*ans[i];
            }
        }
        return sum;
        
    }
};