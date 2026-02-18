class Solution {
public:
    bool hasAlternatingBits(int n) {
        bool t=true;
        string x="";
        /* to see number as bit  (n&1) give me rightmost elemmet */
        while(n > 0){
            x += char((n & 1) + '0');
            n >>= 1;
        }
         for(int i=1;i<x.size();i++){
            if(x[i-1]==x[i]){
                t=false;
            }
         }
        return t;
    }
};