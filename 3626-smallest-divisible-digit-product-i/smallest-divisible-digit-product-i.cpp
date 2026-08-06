class Solution {
public:
    int smallestNumber(int n, int t) {
        for(int i=n;i<=100;i++){
            int x=1;
            int i1=i;
            while(i1){
                int digit=i1%10;
                x*=digit;
                i1/=10;
            }
            if(x%t==0){
                return i;
            }
        }
        return -1;
    
        
    }
};