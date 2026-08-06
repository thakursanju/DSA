class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        vector<int> src={0,0};
        vector<int> dest={n-1,m-1};
        vector<vector<int>> dist(n,vector<int> (m,1e9));
priority_queue<
    pair<int,pair<int,int>>,
    vector<pair<int,pair<int,int>>>,
    greater<pair<int,pair<int,int>>>
> pq;
        pq.push({0,{src[0],src[1]}});
        dist[src[0]][src[1]]=0;
        vector<int> dr={-1,0,1,0};
        vector<int> dc={0,1,0,-1};
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int r=it.second.first;
            int c=it.second.second;
            int dis=it.first;
                if(r == n-1 && c == m-1)
        return dis;
            for(int i=0;i<4;i++){
                int nr=r+dr[i];
                int nc=c+dc[i];
                if(nr>=0&&nr<n&&nc>=0&&nc<m){
                    int edge=abs(heights[r][c]-heights[nr][nc]);
                    int new1=max(dis,edge);
                    if(new1<dist[nr][nc]){
                        dist[nr][nc]=new1;
                        pq.push({new1,{nr,nc}});
                    }

                }
            }

        }
        return -1;
    }
};