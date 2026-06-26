class Solution {
public:
    vector<string> createGrid(int m, int n) {
        // i=1 to i=n && j!=n put #
        // i=0 && j=n put . and return grid 
        vector<string> grid(m,string(n,'#'));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0){
                    grid[i][j]='.';
                }
                else if (j==n-1){
                    grid[i][j]='.';
                }

            }
        }
        return grid;
        
    }
};