class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> nums=prices;
        int pro=0;
        int maxi=0;
        int x=INT_MAX;
        for(int i=0;i<n;i++){
            x=min(x,nums[i]);
            if(x<nums[i]){
                pro=nums[i]-x;
            }
            maxi=max(maxi,pro);
        }
        return maxi;
        
    }
};