
class Solution {
private: 
    void solve(vector<int>& nums,int i,set<vector<int>>& nums1){
        if(i==nums.size()){// one is done move to next 
            nums1.insert(nums);
            return;
        }
        for(int j=i;j<nums.size();j++){
            swap(nums[i],nums[j]);
            solve(nums,i+1,nums1);
            swap(nums[i],nums[j]);
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();
        set<vector<int>> nums1;
        solve(nums,0,nums1);
        return vector<vector<int>>(nums1.begin(), nums1.end());
        
    }
};