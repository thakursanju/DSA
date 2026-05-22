class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int s = 0, e = n - 1;
        int m=s+(e-s)/2;
        
        while (s < e) {
            int m = s + (e - s) / 2; 
            
            if (nums[m] >= nums[0]) {  
                s = m + 1;
            } else { 
                e = m;
            }
        } 
        int pivot=s;
        s=0;
        e=n-1;
        if (nums[pivot]<=target&&target<=nums[n-1]){
            s=pivot;
        }
        else {
            e=pivot-1;
        }
        
         while(s<=e){
             int m=s+(e-s)/2;
                if (nums[m]==target){
                    return m;
                    s=m+1;
                }
                else if (target>nums[m]){
                    
                    s=m+1;
                }
                else{
                    
                    e=m-1;
                    }
               
            }
       return -1;
    }
};
