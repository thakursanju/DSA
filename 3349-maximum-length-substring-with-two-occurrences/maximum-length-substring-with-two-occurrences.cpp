class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n=s.size();
        int len=1;
        int l=0,r=0;
        vector<int> fre(26,0);
        while(l<=r&&r<n){
            fre[s[r]-'a']++;
            while(fre[s[r]-'a']>2){
                fre[s[l]-'a']--;
                l++;
            }
            
            len =max(len,r-l+1);
            r++;
        }
        return len;
        
    }
};