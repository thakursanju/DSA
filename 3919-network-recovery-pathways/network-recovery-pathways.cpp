class Solution {
public:
    using ll = long long;

    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {

        int n = online.size();

        vector<vector<pair<int,int>>> adj(n);
        vector<int> indegree(n,0);

        int mx = 0;

        for(auto &e:edges){
            adj[e[0]].push_back({e[1],e[2]});
            indegree[e[1]]++;
            mx=max(mx,e[2]);
        }

        // Topological order
        queue<int> q;
        for(int i=0;i<n;i++)
            if(indegree[i]==0)
                q.push(i);

        vector<int> topo;

        while(!q.empty()){
            int u=q.front();
            q.pop();
            topo.push_back(u);

            for(auto &[v,w]:adj[u]){
                if(--indegree[v]==0)
                    q.push(v);
            }
        }

        auto check = [&](int lim){

            const ll INF = 4e18;
            vector<ll> dist(n,INF);
            dist[0]=0;

            for(int u:topo){

                if(dist[u]==INF) continue;

                if(u!=0 && u!=n-1 && !online[u]) continue;

                for(auto &[v,w]:adj[u]){

                    if(w<lim) continue;

                    if(v!=n-1 && v!=0 && !online[v]) continue;

                    dist[v]=min(dist[v],dist[u]+(ll)w);
                }
            }

            return dist[n-1]<=k;
        };

        int lo=0,hi=mx,ans=-1;

        while(lo<=hi){

            int mid=lo+(hi-lo)/2;

            if(check(mid)){
                ans=mid;
                lo=mid+1;
            }
            else
                hi=mid-1;
        }

        return ans;
    }
};