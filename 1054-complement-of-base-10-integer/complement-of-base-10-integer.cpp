class Solution {
public:
    int bitwiseComplement(int n) {
        if (n == 0) return 1;  
        int mask = (1LL << (64 - __builtin_clzll(n))) - 1;
        int x = n ^ mask; 
        int i=0;
        long long count=0;
        while (x!=0){
            
            int bit =x&1;
            int digit =x%10;
            if (bit ==1){
           count += (1LL << i);           
            }
            i++;
            x=x>>1;
            
        }
        return count ;
    
    }
};