class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int mx = *max_element(costs.begin(), costs.end());

        vector<int> cnt(mx + 1, 0);

        for (int cost : costs)
            cnt[cost]++;

        int ans = 0;

        for (int cost = 1; cost <= mx; cost++) {
            if (cnt[cost] == 0) continue;

            int canBuy = min(cnt[cost], coins / cost);

            ans += canBuy;
            coins -= canBuy * cost;

            if (coins < cost) break;
        }

        return ans;
    }
};