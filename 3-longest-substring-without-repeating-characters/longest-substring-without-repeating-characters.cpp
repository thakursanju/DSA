class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        int l=0;
        for(int i=0;i<n;i++){
            string t="";
            for(int j=i;j<n;j++){
                if(t.find(s[j])!=string ::npos){
                    break;
                }
                t+=s[j];
            }
            int m=t.size();
            l=max(l,m);
        }
        return l;

        
    }
};