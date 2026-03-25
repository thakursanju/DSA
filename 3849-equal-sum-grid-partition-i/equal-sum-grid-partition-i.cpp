class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        long long n=grid.size();
        long long m=grid[0].size();

        vector<long long> sum(n,0);
        for(long long i=0;i<n;i++){
            for(long long j=0;j<m;j++){
                sum[i]+=grid[i][j];
            }
        }
        vector<long long> sum1(m,0);
        for(long long i=0;i<m;i++){
            for(long long  j=0;j<n;j++){
                sum1[i]+=grid[j][i];
            }
        }
        long long totalRow = 0;
        for(auto x : sum) totalRow += x;

        long long pref = 0;
        for(int i = 0; i < n-1; i++){
            pref += sum[i];
            if(pref == totalRow - pref) return true;
        }
        long long totalCol = 0;
        for(auto x : sum1) totalCol += x;

        pref = 0;
        for(int j = 0; j < m-1; j++){
            pref += sum1[j];
            if(pref == totalCol - pref) return true;
        }

        return false;
    }
};