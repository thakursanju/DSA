class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) { 
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto it : roads){
            int u=it[0];
            int v=it[1];
            int time=it[2];
            adj[u].push_back({v,time});
            adj[v].push_back({u,time});
        }
priority_queue<
    pair<long long, int>,
    vector<pair<long long, int>>,
    greater<pair<long long, int>>
> pq;
        pq.push({0,0});
        vector<long long > dist(n+1,1e18);
        vector<int> ways(n + 1, 0);
        ways[0] = 1;
        dist[0]=0;
        while(!pq.empty()){
            auto it =pq.top();
            pq.pop();
            int sr=it.second;
            long long dis=it.first;
            if(dis>dist[sr]) continue;
            for(auto & it : adj[sr]){
                int adjnode=it.first;
                int w=it.second;
                if(dis+w<dist[adjnode]){
                    dist[adjnode]=dis+w;
                ways[adjnode]=ways[sr];
                pq.push({dist[adjnode],adjnode});
                }
                else if (dis+w==dist[adjnode]){
                    ways[adjnode]=(ways[adjnode]+ways[sr])%1000000007;
                }
            }

        }
        return ways[n-1];

    }
};