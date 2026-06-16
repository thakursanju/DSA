class Solution {
public:
    string processStr(string s) {
        int n =s.size();
        string t="";
        for(int i=0;i<n;i++){
            if(s[i] >= 'a' && s[i] <= 'z'){
                t+=s[i];
            }
            else if (s[i]=='#'){
                t=t+t;
            }
            else if (s[i]=='%'){
                reverse(t.begin(),t.end());
            }
            else{
                 if (!t.empty()) {
                    t.pop_back();
                 }

            }

        }
        return t;
        
    }
};