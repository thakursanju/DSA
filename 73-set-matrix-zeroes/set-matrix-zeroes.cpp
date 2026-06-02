class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<pair<int,int>> al;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0){
                    al.push_back({i,j});
                }
            }
        }
        for(auto i : al){
            for(int j=0;j<m;j++){
                matrix[i.first][j]=0;
            }
        }
        for(auto i : al){
            for(int j=0;j<n;j++){
                matrix[j][i.second]=0;
            }
        }  
    }
};