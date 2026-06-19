class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n= gain.size();
        int sum=0;
        int ans=0;
        for(auto s : gain){
            sum+=s;
            ans=max(ans,sum);
        }
        return ans;
        
    }
};