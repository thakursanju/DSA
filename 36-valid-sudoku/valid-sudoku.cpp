class Solution {
private: 
 bool isvalid(int r,int c,vector<vector<char>>& board){
    if(board[r][c]=='.') return true;
    for(int i=0;i<9;i++){
        if(c!=i&&board[r][c]==board[r][i]) return false;
         if(r!=i&&board[r][c]==board[i][c]) return false;
        if((3*(r/3)+i/3!=r&&3*(c/3)+i%3!=c)&&board[3*(r/3)+i/3][3*(c/3)+i%3]==board[r][c]){
            return false;
        }

    }
    return true;
 }
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!isvalid(i,j,board)){
                    return false;
                }
            }
        }
        return true;
    }
};
