class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> mat;
        for(int i=0;i<numRows;i++){
            vector<int> mat1(i+1);
            for(int j=0;j<=i;j++){
                if(j==0||j==i){
                    mat1[j]=1;
                }
                else{
                    mat1[j]=mat[i-1][j-1]+mat[i-1][j];
                }
            }
            mat.push_back(mat1);
        }
        return mat;
        
        
    }
};