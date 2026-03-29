class Solution {
public:
    bool canBeEqual(string s1, string s2) {


        if(s1==s2) return 1;
        string x=s1;
        swap(x[0],x[2]);
        if(x==s2) return 1;
        x=s1;
        swap(x[1],x[3]);
        if(x==s2) return 1;
        x=s1;
        swap(x[0],x[2]);
        swap(x[1],x[3]);
        if(x==s2) return 1;
        return 0;
        
    }
};