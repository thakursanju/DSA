class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n=nums.size();
        int ans=    INT_MAX;
        unordered_map<int,vector<int>> sd;
        bool g=false;
        for(int i=0;i<n;i++){
            sd[nums[i]].push_back(i);
        }

        if(n<3){
            return -1;
        }
        else{
            for( auto& p: sd){
            vector<int> &index=p.second;
            int m=index.size();
            if(index.size()>=3){
                for(int i=0;i+2<m;i++){
                        ans=min(ans,2*(index[i+2]-index[i]));
                        g=true;
                    }
                }
            } 
            }

    return g?ans:-1;
    }
};