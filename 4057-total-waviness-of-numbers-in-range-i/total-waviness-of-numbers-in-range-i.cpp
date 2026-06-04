class Solution {
public:
    int totalWaviness(int num1, int num2) {
        if (num2<100){
            return 0;
        }
        int c=0;
        bool ok = false;
        for(int i=num1;i<=num2;i++){
            string s=to_string(i);
            for(int j=1;j<s.size()-1;j++){
                int cur = s[j] - '0';
                int left = s[j - 1] - '0';
                int right = s[j + 1] - '0';

                if(cur > left && cur > right) {
                    c++;
                }
                else if (cur < left && cur < right){
                    c++;
                }
                else if ( s.size()>3){
                    ok=true;
                }
            }
        }

        return c;
        
        
    }
};