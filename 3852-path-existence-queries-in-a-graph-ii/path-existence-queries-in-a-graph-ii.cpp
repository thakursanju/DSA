#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, x) for(int i = 0; i < int(x); i++)
#define all(x) (x).begin(), (x).end()

using P = pair<int, int>;
const int INF = 1001001001;

class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<pair<int,int>> to(n);
        rep(i, n) to[i] = {nums[i], i};
        sort(all(to));
        vector<int> pos(n);
        rep(i, n) {
            pos[to[i].second] = i;
        }

        vector<int> f(n);
        int j = 0;
        for(int i = 0; i < n; i++) {
            while (j < n && to[j].first - to[i].first <= maxDiff) {
                j++;
            }
            f[i] = j - 1;
        }

        vector<int> comp(n);
        comp[0] = 0;
        for(int i = 1; i < n; i++) {
            if (to[i].first - to[i-1].first > maxDiff) 
                comp[i] = comp[i-1] + 1;
            else 
                comp[i] = comp[i-1];
        }

        int LOG = 17; 
        vector up(LOG, vector<int>(n));
        for(int i = 0; i < n; i++) {
            up[0][i] = f[i];
        }
        for(int k = 1; k < LOG; k++) {
            for(int i = 0; i < n; i++) {
                int mid = up[k-1][i];
                up[k][i] = (mid < 0 ? -1 : up[k-1][mid]);
            }
        }

        vector<int> ans;
        ans.reserve(queries.size());
        for(auto &q : queries) {
            int u = q[0], v = q[1];
            int pu = pos[u], pv = pos[v];
            if (comp[pu] != comp[pv]) {
                ans.push_back(-1);
                continue;
            }
            if (pu > pv) swap(pu, pv);
            if (pu == pv) {
                ans.push_back(0);
                continue;
            }

            int curr = pu, dist = 0;
            for(int k = LOG-1; k >= 0; k--) {
                if (up[k][curr] < pv) {
                    curr = up[k][curr];
                    dist += (1 << k);
                }
            }
            if (f[curr] >= pv) {
                ans.push_back(dist + 1);
            } else {
                ans.push_back(-1);
            }
        }
        return ans;
    }
};