class Solution {
   bool dfs(int node, vector<vector<int>>& adj, vector<int>& state) {

        state[node] = 1;

        for (int nbr : adj[node]) {

            if (state[nbr] == 1)
                return true; 

            if (state[nbr] == 0) {
                if (dfs(nbr, adj, state))
                    return true;
            }
        }

        state[node] = 2;
        return false;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for( auto &p : prerequisites){
            adj[p[1]].push_back(p[0]);
        }
        vector<int> state(numCourses,0);
        for(int i=0;i<numCourses;i++){
            if(state[i]==0&&dfs(i,adj,state))
                return false;
        }
        return true;
        
    }
};