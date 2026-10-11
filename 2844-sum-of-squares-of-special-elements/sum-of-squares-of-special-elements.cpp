class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int n =nums.size();
        int sum=0;
        for (int i=0;i<n;i++){
            if(i==0){
                sum+=nums[0]*nums[0];
            }
            else if (n%(i+1)==0){
                sum+=nums[i]*nums[i];
            }
        }
        return sum;
    }
};