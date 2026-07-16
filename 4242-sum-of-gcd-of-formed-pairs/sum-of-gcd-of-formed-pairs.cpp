class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n=nums.size();
        vector<int> pregcd(n);
        int mx=nums[0];
        pregcd[0]=nums[0];
        for(int i=1;i<n;i++){
            mx=max(mx,nums[i]);
            pregcd[i]=__gcd(nums[i],mx);
        }
        sort(pregcd.begin(),pregcd.end());
        long long sum=0;
        for(int i=0;i<n/2;i++){
            sum+=__gcd(pregcd[i],pregcd[n-1-i]);
        }
        return sum;
        
    }
};