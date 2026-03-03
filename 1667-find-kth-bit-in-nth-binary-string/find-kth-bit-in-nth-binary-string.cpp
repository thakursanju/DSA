class Solution {
public:
    char findKthBit(int n, int k) {
        string s1 = "0";
        for(int i = 2; i <= n; i++) {
            string temp = s1;
            for(char &c : temp) {
                if(c == '0') c = '1';
                else c = '0';
            }
            reverse(temp.begin(), temp.end());
            s1 = s1 + "1" + temp;
        }
        return s1[k-1];
    }
};