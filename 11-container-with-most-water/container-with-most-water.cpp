class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int l=0;
        int r=n-1;
        int mx=INT_MIN;
        while(l<=r){
            int m=min(height[l],height[r]);
            int w=r-l;
            mx=max(mx,w*m);
            if(height[l]<height[r]){
                l++;
            }
            else{
                r--;
            }
        }
        return mx;
        
    }
};