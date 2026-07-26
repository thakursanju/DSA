class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        // Edge case: Total flowers needed is greater than available flowers
        long long totalFlowersNeeded = (long long)m * k;
        if (bloomDay.size() < totalFlowersNeeded) return -1;
        
        int l = *min_element(bloomDay.begin(), bloomDay.end());
        int r = *max_element(bloomDay.begin(), bloomDay.end());
        int ans = -1;
        
        while (l <= r) {
            int mid = l + (r - l) / 2;
            
            if (canMakeBouquets(bloomDay, m, k, mid)) {
                ans = mid;       // Try to find a smaller valid day
                r = mid - 1;
            } else {
                l = mid + 1;     // We need more days
            }
        }
        
        return ans;
    }

private:
    bool canMakeBouquets(const vector<int>& bloomDay, int m, int k, int days) {
        int bouquets = 0;
        int consecutiveFlowers = 0;
        
        for (int bloom : bloomDay) {
            if (bloom <= days) {
                consecutiveFlowers++;
                if (consecutiveFlowers == k) {
                    bouquets++;
                    consecutiveFlowers = 0; // Reset for the next bouquet
                }
            } else {
                consecutiveFlowers = 0; // Streak broken
            }
            
            if (bouquets >= m) return true;
        }
        
        return bouquets >= m;
    }
};