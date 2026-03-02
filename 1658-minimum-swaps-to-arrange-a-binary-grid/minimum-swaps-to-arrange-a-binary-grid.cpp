class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> last1(n, -1);

        for (int i = 0; i < n; i++) {
            for (int j = n - 1; j >= 0; j--) {
                if (grid[i][j] == 1) {
                    last1[i] = j;
                    break;
                }
            }
        }

        int ans = 0;

        for (int i = 0; i < n; i++) {
            int j = i;
            while (j < n && last1[j] > i) j++;

            if (j == n) return -1;

            while (j > i) {
                swap(last1[j], last1[j - 1]);
                ans++;
                j--;
            }
        }

        return ans;
    }
};