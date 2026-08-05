class Solution {
public:
    void dfs(int node, vector<int> adj[], vector<int> &vis) {
        vis[node] = 1;
        for(auto &i : adj[node]) {
            if(!vis[i]) {
                dfs(i, adj, vis);
            }
        }
    }
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<int> adj[n];
        for(auto & i : invocations) {
            int u = i[0];
            int v = i[1];
            adj[u].push_back(v);
        }
        vector<int> vis(n, 0);
        dfs(k, adj, vis);
        vector<int> ans;
        for(auto &i : invocations) {
            int u = i[0];
            int v = i[1];
            if(!vis[u] && vis[v]) {
                for(int i = 0; i < n; i++) ans.push_back(i);
                return ans;
            }
        }
        for(int i = 0; i < n; i++) {
            if(!vis[i]) ans.push_back(i);
        }
        return ans;
    }
};