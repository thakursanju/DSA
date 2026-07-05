class Solution {
public:
bool canMakeSubsequence(string s, string t) {
    int n = s.size(), m = t.size();
    if (n > m) return false;

    // pre[i] = earliest next-available t-position after matching s[0..i-1]
    // INF means matching failed
    const int INF = m + 1;
    vector<int> pre(n + 1, INF);
    pre[0] = 0;
    for (int i = 0; i < n; i++) {
        if (pre[i] == INF) break;
        int j = pre[i];
        while (j < m && t[j] != s[i]) j++;
        pre[i + 1] = (j < m) ? j + 1 : INF;
    }

    // Already a subsequence?
    if (pre[n] != INF) return true;

    // suf[i] = latest t-position where s[i..n-1] starts matching from right
    // -1 means matching failed
    vector<int> suf(n + 1, -1);
    suf[n] = m;
    for (int i = n - 1; i >= 0; i--) {
        int j = suf[i + 1] - 1;
        while (j >= 0 && t[j] != s[i]) j--;
        suf[i] = (j >= 0) ? j : -1;
    }

    // Try replacing s[i]: need pre[i] < suf[i+1]
    // pre[i]    = first free slot in t after matching s[0..i-1]
    // suf[i+1]  = start of the right-side match for s[i+1..n-1]
    // A free slot must exist between them for the replaced character
    for (int i = 0; i < n; i++) {
        if (pre[i] == INF) break;          // left side unmatched
        if (suf[i + 1] == -1) continue;   // right side unmatched
        if (pre[i] < suf[i + 1]) return true;
    }
    return false;
}
};