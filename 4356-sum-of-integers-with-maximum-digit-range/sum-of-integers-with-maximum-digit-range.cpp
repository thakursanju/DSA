class Solution {
public:
    int maxDigitRange(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans;
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            int mx=0;
            int mn=9; 
            int num=nums[i];
                while(num>0){
                    int digit=num%10;
                    mx = max(mx, digit);
                    mn = min(mn, digit);
                    num/=10;
                }
                ans.push_back(mx-mn);
        }
        int ma=INT_MIN;
        for(int i=0;i<ans.size();i++){
            ma=max(ma,ans[i]);
        }
        for(int i=0;i<n;i++){
            if(ans[i]!=ma){
                sum-=nums[i];
            }
        }
        return sum;
        
  
    }
};