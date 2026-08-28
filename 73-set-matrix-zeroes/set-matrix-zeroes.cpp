class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n =matrix.size();
        int m =matrix[0].size();
        vector<int> r;
        vector<int> c;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0){
                    c.push_back(j);
                    r.push_back(i);
                }
            }
        }
        for(int i=0;i<r.size();i++){
            for(int j=0;j<m;j++){
                matrix[r[i]][j]=0;
            }
        }
        for(int i=0;i<c.size();i++){
            for(int j=0;j<n;j++){
                matrix[j][c[i]]=0;
            }
        }
        
    }
};