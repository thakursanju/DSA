class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto &it : flights){
            int u=it[0];
            int v=it[1];
            int cost=it[2];
            adj[u].push_back({v,cost});
        }
        queue<pair<int,pair<int,int>>> q;// stop,node,dist
        vector<int> dist(n,1e9);
        dist[src]=0;
        q.push({0,{src,0}});
 
        while(!q.empty()){
            auto it =q.front();
            q.pop();
            int stops=it.first;
            int node=it.second.first;
            int dis=it.second.second;
            if(stops>k){
                continue;
            }
            for( auto i :adj[node]){
                int adjnode=i.first;
                int costadj=i.second;
                if(dis+costadj<dist[adjnode]&&stops<=k){
                    dist[adjnode]=dis+costadj;
                    q.push({stops+1,{adjnode,dis+costadj}});

                }

            }



        }
        if(dist[dst]==1e9){
            return -1;
        }
        return dist[dst];



    }
};