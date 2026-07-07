class Solution {
public:
    long long sumAndMultiply(int n) {
       vector<int> ans;
       long long sum=0;
        while(n){
            int digit=n%10;
            sum+=digit;
            if(digit>0){
                ans.push_back(digit);
            }
            n/=10;
        }
        reverse(ans.begin(),ans.end());
        long long x=0;
        for(int i=0;i<ans.size();i++){
            x=x*10+ans[i];
        }
        return x*sum;
    }
};