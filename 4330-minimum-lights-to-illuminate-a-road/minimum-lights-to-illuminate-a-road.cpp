
        // li[i] =0; no working bulb
        // li[i]!=0 ==v; v>0  max(0,i-v) to min(n-1,i+v)
        // add nulb 
        // at pos j range max(0,j-1) to min (n-1,j+1);

class Solution {
public:
    int minLights(vector<int>& lights) {
        int n = lights.size();

        vector<int> diff(n + 1, 0);

        // Mark coverage of existing bulbs
        for (int i = 0; i < n; i++) {
            if (lights[i] > 0) {
                int l = max(0, i - lights[i]);
                int r = min(n - 1, i + lights[i]);

                diff[l]++;
                if (r + 1 < n)
                    diff[r + 1]--;
            }
        }

        int ans = 0;
        int cover = 0;

        for (int i = 0; i < n; i++) {
            cover += diff[i];

            if (cover == 0) {
                ans++;

                // New bulb placed at min(i+1, n-1)
                cover++;

                int end = min(n - 1, i + 2);
                if (end + 1 < n)
                    diff[end + 1]--;
            }
        }

        return ans;
    }
};