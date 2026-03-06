class Solution {
public:
    bool checkOnesSegment(string s) {
        int n=s.size();
        bool t=true;

        int c=0;
        for(int i=1;i<n;i++){
            if(s[i-1]!=s[i]){
                c++;
            }
        }
        if(c>1){
            t=false;
        }

        return t;
    }
};