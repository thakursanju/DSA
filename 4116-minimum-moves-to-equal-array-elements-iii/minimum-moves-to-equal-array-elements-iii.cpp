class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n =nums.size();
        int mx=0;
        int sum=0;
        for(int i=0;i<n;i++){
            mx=max(mx,nums[i]);
        }
        for(int i=0;i<n;i++){
            sum+=mx-nums[i];
        }
        return sum;
        
    }
};