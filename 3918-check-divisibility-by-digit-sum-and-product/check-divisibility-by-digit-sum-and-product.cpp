class Solution {
public:
    bool checkDivisibility(int n) {
        int x=n;
        int sum=0;
        int mul=1;
        while(x){
            int d=x%10;
            sum+=d;
            mul*=d;
            x/=10;
        }
        return (n%(sum+mul)==0)?1:0;
        
    }
};