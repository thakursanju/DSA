class Solution {
public:
    int maxProduct(int n) {
        vector<int> ans;
        while(n){
            int digit=n%10;
            ans.push_back(digit);
            n/=10;
        }
        int m=ans.size();
        sort(ans.begin(),ans.end());
        return ans[m-2]*ans[m-1];
        
    }
};