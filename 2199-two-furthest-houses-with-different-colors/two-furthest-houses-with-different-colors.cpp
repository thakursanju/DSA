class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n=colors.size();
        int ans=0;
        for(int i=0;i<n;i++){
            int a=0;
            for(int j=i;j<n;j++){
                if(colors[i]!=colors[j]){
                    a=j-i;
                    ans=max(ans,a);
                }
            }
        }
     return ans;   
    }
};