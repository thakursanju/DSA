class Solution {
public:
    int countCommas(int n) {
        if(n<1000) return 0;
        int x=n;
        int y=0;
        vector<int> ans;
        while(x){
            int d=x%10;
            ans.push_back(d);
            x/=10;
        }
        reverse(ans.begin(),ans.end());
        if(ans.size()==4){
        for(int i=1;i<ans.size();i++){
            y=ans[i]+10*y;
        }
        if(ans[0] == 1) {
            return y + 1;
        }
        else {
            return (ans[0] - 1) * 1000 + y + 1;
        }
    }

        else {
            for(int i = 1; i < ans.size(); i++) {
                y = ans[i] + 10 * y;
            }
        

            return n - 999;
        }
        
        
    }
};