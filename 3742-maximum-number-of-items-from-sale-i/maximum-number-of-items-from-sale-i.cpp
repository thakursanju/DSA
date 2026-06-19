class Solution {
int dp11(int i,vector<vector<int>>& items, int j,vector<vector<int>>& dp,vector<int> &fc,int mnPrice){
    if(j<0){
        return -1e9;
    }
    if(i==items.size()){
        return j / mnPrice;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int take =1+fc[i]+dp11(i+1,items,j-items[i][1],dp,fc,mnPrice);
    int notake=0+dp11(i+1,items,j,dp,fc,mnPrice);
    int ans = max(take,notake);
    return dp[i][j]=ans;

    
}
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        sort(items.begin(),items.end());
        int n=items.size();
        vector<int> fc(n,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i!=j&&items[j][0]%items[i][0]==0){
                    fc[i]++;
                }
            }
        }
        int mnPrice = 1e9;
        for (auto &v : items) {
            mnPrice = min(mnPrice, v[1]);
        }
        vector<vector<int>> dp(n,vector<int>(budget+1,-1));
        return dp11(0,items,budget,dp,fc,mnPrice);
    }
};