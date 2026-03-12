#include <bits/stdc++.h>
using namespace std;

const int maxn = 100005;

int parent[maxn], sz[maxn];
int n, k;

bool comp(const vector<int>& a, const vector<int>& b){
    return a[2] > b[2];
}

class Solution {
public:

    void make_set(){
        for(int i = 0; i < n; i++){
            parent[i] = i;
            sz[i] = 1;
        }
    }

    int find_set(int x){
        if(x == parent[x]) return x;
        return parent[x] = find_set(parent[x]);
    }

    bool union_set(int a, int b){
        a = find_set(a);
        b = find_set(b);

        if(a == b) return false;

        if(sz[a] < sz[b]) swap(a, b);

        parent[b] = a;
        sz[a] += sz[b];

        return true;
    }

    bool kruskal(int t, const vector<vector<int>>& edges){

        make_set();

        int edges_used = 0;
        int upgrades = 0;

        // first process must edges
        for(auto &e : edges){
            int u = e[0], v = e[1], w = e[2], must = e[3];

            if(must){
                if(w < t) return false;

                if(!union_set(u,v)) return false;

                edges_used++;
            }
        }

        // process other edges
        for(auto &e : edges){
            int u = e[0], v = e[1], w = e[2], must = e[3];

            if(must) continue;

            if(2*w >= t && union_set(u,v)){
                edges_used++;

                if(w < t) upgrades++;

                if(upgrades > k) return false;

                if(edges_used == n-1) break;
            }
        }

        return edges_used == n-1;
    }

    int maxStability(int _n, vector<vector<int>>& ed, int _k) {

        n = _n;
        k = _k;

        sort(ed.begin(), ed.end(), comp);

        int l = 1, r = 2000000000;
        int ans = -1;

        while(l <= r){
            int mid = l + (r-l)/2;

            if(kruskal(mid, ed)){
                ans = mid;
                l = mid + 1;
            }
            else{
                r = mid - 1;
            }
        }

        return ans;
    }
};