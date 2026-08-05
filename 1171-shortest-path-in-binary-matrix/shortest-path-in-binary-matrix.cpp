class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,pair<int,int>>> q;
        vector<vector<int>> dist(n,vector<int>(m,1e9)); 
        vector<int> src={0,0};
        vector<int> dest={n-1,n-1};
        if(n==1&&grid[0][0]==1) return -1;
        if(n==1&&grid[0][0]==0) return 1;
        q.push({1,{src[0],src[1]}});
        
        dist[src[0]][src[1]]=1;
        vector<int> dr={-1, -1, 0, 1, 1, 1, 0, -1};
        vector<int> dc={0,  1, 1, 1, 0,-1,-1, -1};
        if (grid[0][0] == 1 || grid[n-1][n-1] == 1)
    return -1;
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int dis=it.first;
            int r=it.second.first;
            int c=it.second.second;
            for(int i=0;i<8;i++){
                int nr=r+dr[i];
                int nc=c+dc[i];
                if(nr>=0&&nr<n&&nc>=0&&nc<m&&grid[nr][nc]==0&&dis+1<dist[nr][nc]){
                    dist[nr][nc]=1+dis;
                    if(nr==dest[0]&&nc==dest[1]){
                        return 1+dis;
                    }
                    q.push({dis + 1, {nr, nc}});
                }
                

            }
        }
        return -1;
        

    }
};