class Solution {
private: 
    void solve(vector<int>& nums,int i,vector<vector<int>>& nums1){
        if(i==nums.size()){
            nums1.push_back(nums);
            return;
        }
        for(int j=i;j<nums.size();j++){
            swap(nums[i],nums[j]);
            solve(nums,i+1,nums1);
            swap(nums[i],nums[j]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> nums1;
        solve(nums,0,nums1);
        return nums1;

        
    }
};