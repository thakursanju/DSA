class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        int mx=0;
        if(n==1){
            return nums[0];
        }
        int x=INT_MIN;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            mx=max(mx,sum);
            if(sum<0) sum=0;
            x=max(x,nums[i]);  
        }
        if(mx==0){
            return x;
        }
        return mx;
        
    }
};