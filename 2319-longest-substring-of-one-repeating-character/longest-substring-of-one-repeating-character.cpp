class SegmentTree {
    struct Node {
        int len;
        int pref, suff, best;
        char leftChar, rightChar;

        Node() : len(0), pref(0), suff(0), best(0),
                 leftChar(0), rightChar(0) {}

        Node(char c)
            : len(1), pref(1), suff(1), best(1),
              leftChar(c), rightChar(c) {}
    };

    vector<Node> tree;
    string &s;

    Node merge(const Node &a, const Node &b) {
        if (a.len == 0) return b;
        if (b.len == 0) return a;

        Node res;
        res.len = a.len + b.len;
        res.leftChar = a.leftChar;
        res.rightChar = b.rightChar;

        // Prefix
        res.pref = a.pref;
        if (a.pref == a.len && a.rightChar == b.leftChar)
            res.pref += b.pref;

        // Suffix
        res.suff = b.suff;
        if (b.suff == b.len && a.rightChar == b.leftChar)
            res.suff += a.suff;

        // Best answer inside this segment
        res.best = max(a.best, b.best);

        // A repeating substring can cross the boundary
        if (a.rightChar == b.leftChar)
            res.best = max(res.best, a.suff + b.pref);

        return res;
    }

    void build(int node, int l, int r) {
        if (l == r) {
            tree[node] = Node(s[l]);
            return;
        }

        int mid = l + (r - l) / 2;

        build(node * 2, l, mid);
        build(node * 2 + 1, mid + 1, r);

        tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
    }

    void update(int node, int l, int r, int idx, char c) {
        if (l == r) {
            tree[node] = Node(c);
            return;
        }

        int mid = l + (r - l) / 2;

        if (idx <= mid)
            update(node * 2, l, mid, idx, c);
        else
            update(node * 2 + 1, mid + 1, r, idx, c);

        tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
    }

public:
    SegmentTree(string &str) : s(str) {
        int n = s.size();
        tree.resize(4 * n);
        build(1, 0, n - 1);
    }

    void update(int idx, char c) {
        s[idx] = c;
        update(1, 0, s.size() - 1, idx, c);
    }

    int getBest() {
        return tree[1].best;
    }
};

class Solution {
public:
    vector<int> longestRepeating(
        string s,
        string queryCharacters,
        vector<int>& queryIndices
    ) {
        SegmentTree st(s);

        vector<int> ans;

        for (int i = 0; i < queryIndices.size(); i++) {
            st.update(queryIndices[i], queryCharacters[i]);
            ans.push_back(st.getBest());
        }

        return ans;
    }
};