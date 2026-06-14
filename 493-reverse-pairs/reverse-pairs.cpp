
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<
    long long,
    null_type,
    less_equal<long long>,
    rb_tree_tag,
    tree_order_statistics_node_update
> ordered_set;class Solution {
public:
    int reversePairs(vector<int>& nums) {
        ordered_set st;
        long long ans = 0;

        for (int x : nums) {

            ans += st.size() - st.order_of_key(2LL * x + 1);

            st.insert(x);
        }

        return ans;
    }
};