class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n =nums.size();
        sort(nums.begin(),nums.end());
        vector<int> ans;
        for(int i=0;i<n;i++){
            int c=1;
            while(i+c<n&&nums[i]==nums[i+c]){
                c++;
                
            }
            if(c>n/3){
                ans.push_back(nums[i]);
            }
           

        }
        ans.erase(unique(ans.begin(), ans.end()), ans.end());

        return ans;

    }
};