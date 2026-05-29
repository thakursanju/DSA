class Solution {
public:
    int minElement(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans;
        for(int i=0;i<n;i++){
            int x=nums[i];
            int sum=0;
            while(x){
                int y=x%10;
                sum+=y;
                x/=10;
            }
            ans.push_back(sum);
        }
        int mn= *min_element(ans.begin(), ans.end());
        return mn;
        
    }
};