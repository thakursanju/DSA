class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        int ans = 0;
        int primeMask = (1<<2) | (1<<3) | (1<<5) | (1<<7) | 
                        (1<<11) | (1<<13) | (1<<17) | (1<<19);

        for (int num = left; num <= right; num++) {
            int bits = __builtin_popcount(num);
            if (primeMask & (1 << bits)) ans++;
        }
        return ans;
        
    }
};