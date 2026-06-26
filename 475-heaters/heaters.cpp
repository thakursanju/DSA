class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());

        int ans = 0;

        for (int house : houses) {
            auto it = lower_bound(heaters.begin(), heaters.end(), house);

            int right = (it == heaters.end()) ? INT_MAX : *it - house;
            int left = (it == heaters.begin()) ? INT_MAX : house - *prev(it);

            ans = max(ans, min(left, right));
        }

        return ans;
    }
};