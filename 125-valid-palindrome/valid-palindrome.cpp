class Solution {
public:
    bool isPalindrome(string s) {
        int n=s.size();
        string t="";
        for(int i=0;i<n;i++){
            if(s[i]>='a'&&s[i]<='z'||s[i]>='A'&&s[i]<='Z'||s[i]>='0'&&s[i]<='9'){
                t+=tolower(s[i]);
            }
        }
        int l=0;
        bool t1=true;
        int r=t.size()-1;
        while(l<=r){
            if(t[l]==t[r]){
                l++;
                r--;
            }
            else{
                t1=false;
                break;
            }

        }
        return t1;
        
    }
};