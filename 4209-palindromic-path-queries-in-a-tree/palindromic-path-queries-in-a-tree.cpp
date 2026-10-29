
class Solution {
public:
    int n, timer;
    vector<vector<int>> adj;
    vector<int> tin, tout, depth, parent;
    vector<vector<int>> up;
    vector<int> bit;
    string s;

    void dfs(int u, int p) {
        tin[u] = ++timer;
        parent[u] = p;
        up[0][u] = p;

        for (int j = 1; j < (int)up.size(); j++)
            up[j][u] = up[j - 1][up[j - 1][u]];

        for (int v : adj[u]) {
            if (v == p) continue;
            depth[v] = depth[u] + 1;
            dfs(v, u);
        }

        tout[u] = timer;
    }

    void updateBIT(int i, int val) {
        for (; i <= n; i += i & -i)
            bit[i] ^= val;
    }

    int queryBIT(int i) {
        int res = 0;
        for (; i > 0; i -= i & -i)
            res ^= bit[i];
        return res;
    }

    int pref(int u) {
        return queryBIT(tin[u]);
    }

    int lca(int u, int v) {
        if (depth[u] < depth[v]) swap(u, v);

        int diff = depth[u] - depth[v];
        for (int j = 0; j < (int)up.size(); j++)
            if (diff & (1 << j))
                u = up[j][u];

        if (u == v) return u;

        for (int j = (int)up.size() - 1; j >= 0; j--) {
            if (up[j][u] != up[j][v]) {
                u = up[j][u];
                v = up[j][v];
            }
        }

        return parent[u];
    }

    vector<bool> palindromePath(int N, vector<vector<int>>& edges,
                                string str, vector<string>& queries) {
        n = N;
        s = str;
        timer = 0;
        adj.assign(n, {});
        tin.resize(n);
        tout.resize(n);
        depth.assign(n, 0);
        parent.resize(n);

        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        int LOG = 1;
        while ((1 << LOG) <= n) LOG++;
        up.assign(LOG, vector<int>(n, 0));
        bit.assign(n + 1, 0);

        dfs(0, 0);

        // Euler entry/exit XOR difference:
        // each node's character affects its entire subtree.
        for (int u = 0; u < n; u++) {
            int mask = 1 << (s[u] - 'a');
            updateBIT(tin[u], mask);
            if (tout[u] < n)
                updateBIT(tout[u] + 1, mask);
        }

        vector<bool> ans;

        for (string &q : queries) {
            string type = q.substr(0, q.find(' '));
            stringstream ss(q);
            string cmd;
            int u, v;
            ss >> cmd >> u;

            if (cmd == "update") {
                char c;
                ss >> c;

                int delta = (1 << (s[u] - 'a')) ^ (1 << (c - 'a'));
                updateBIT(tin[u], delta);
                if (tout[u] < n)
                    updateBIT(tout[u] + 1, delta);
                s[u] = c;
            } else {
                ss >> v;
                int w = lca(u, v);
                int mask = pref(u) ^ pref(v) ^ (1 << (s[w] - 'a'));

                ans.push_back((mask & (mask - 1)) == 0);
            }
        }

        return ans;
    }
};
