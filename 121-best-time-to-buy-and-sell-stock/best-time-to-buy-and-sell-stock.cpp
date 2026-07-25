class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int minp=INT_MAX;
        int pro=0;
        for(int p : prices){
            minp=min(minp,p);
            pro=max(pro,p-minp);
        }
        return pro;

        
    }
};