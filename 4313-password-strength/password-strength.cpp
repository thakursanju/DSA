class Solution {
public:
    int passwordStrength(string password) {
        int n=password.size();
        int sum=0;
        string ans;
        for(char c:password) if(ans.find(c)==string::npos) ans+=c;
        for(char x : ans){
            if(x>='a'&&x<='z'){
                sum+=1;
            }
            else if (x>='A'&&x<='Z'){
                sum+=2;
            }
            else if (x=='!'||x=='@'||x=='#'||x=='$'){
                sum+=5;
            }
            else{
                sum+=3;
            }
        }

        return sum;
    }
};