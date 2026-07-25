class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int ans=0;
        bool t=false;
        for(int i=0;i<n;i++){
            if(nums[i]==target){
                ans=i;
                t=true;
                break;
            }
        }
        if(!t){
            return -1;

        } 
         return ans;

    }
};