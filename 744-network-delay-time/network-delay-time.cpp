class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto &it : times){
            int u=it[0];
            int v=it[1];
            int cost=it[2];
            adj[u].push_back({v,cost});
        }
        vector<int> dist(n+1,1e9);
        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        > pq;
        pq.push({0,{k}});
        dist[k]=0;
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int node=it.second;
            int dis=it.first;
            if(dis>dist[node]) continue;
            for(auto &it: adj[node]){
                int w=it.second;
                int adjnode=it.first;
                if(dis+w<dist[adjnode]){
                    dist[adjnode]=dis+w;
                    pq.push({dist[adjnode],adjnode});
                }    
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            if(dist[i]==1e9){
                return -1;
            }
            ans=max(ans,dist[i]);
        }
        return ans;

    }
};