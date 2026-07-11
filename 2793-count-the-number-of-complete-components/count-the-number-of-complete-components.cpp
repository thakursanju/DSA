class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto &e : edges){
            int u=e[0];
            int v=e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        queue<int> q;
        q.push(0);
        vector<int> vis(n,0);
        int c=0;
        for(int i=0;i<n;i++){
            if(vis[i]) continue;
         queue<int> q;
        q.push(i);
        vis[i]=1;
        int edgeSum =0;
        int nodes=0;
        while(!q.empty()){
            int node=q.front();
            q.pop();
                edgeSum += adj[node].size();
                nodes++;
            for(int it : adj[node]){
                if(!vis[it]){
                    vis[it]=1;
                    q.push(it);
                }
            }
        }
          int   edges = edgeSum / 2;
            if(edges == nodes * (nodes - 1) / 2){
                c++;
            }
        }
        
        return c;
    }
};