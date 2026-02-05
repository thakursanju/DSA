class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> result(n);
        for(int i=0;i<n;i++){
            int x=nums[i];
            int change =i+x;
            while(change<0) change+=n;
            while(change>=n) change-=n;

            result[i]=nums[change];

        }
       return result; 
    }
};