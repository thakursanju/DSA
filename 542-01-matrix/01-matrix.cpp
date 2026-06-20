class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        //bfs min counter multi source
        vector<vector<int>> vis(n,vector<int>(m,0));
        vector<vector<int>> dis(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>> q; 
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    q.push({{i,j},0});
                    vis[i][j]=1;
                }

            }
        }
        int delrow[]={-1,0,+1,0};
        int delcol[]={0,+1,0,-1};
        while(!q.empty()){
            int r=q.front().first.first;
            int c=q.front().first.second;
            int d=q.front().second;
            q.pop();
            dis[r][c]=d;
            for(int i=0;i<4;i++){
                int nebr=r+delrow[i];
                int nebc=c+delcol[i];
                if(nebr>=0&&nebr<n&&nebc>=0&&nebc<m&&!vis[nebr][nebc]){
                        vis[nebr][nebc]=1;
                        dis[nebr][nebc]=d+1;
                        q.push({{nebr, nebc}, d+1});              
                }

            }

        }
        return dis;
        
    }
};