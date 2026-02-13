#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // 1) longest run of a single character
    int longestRun(const string& s) {
        int best = 1, cur = 1;
        for (size_t i = 1; i < s.size(); ++i) {
            if (s[i] == s[i-1]) ++cur;
            else {
                best = max(best, cur);
                cur = 1;
            }
        }
        best = max(best, cur);
        return best;
    }

    // 2) longest substring with only letters x,y (no z) and #x == #y
    int longestTwoChars(const string& s, char x, char y, char forbidden) {
        int n = (int)s.size();
        int best = 0;
        int i = 0;
        while (i < n) {
            // skip forbidden letters
            while (i < n && s[i] == forbidden) ++i;
            if (i == n) break;
            int segStart = i;
            // find end of segment without forbidden
            while (i < n && s[i] != forbidden) ++i;
            int segEnd = i;                 // exclusive

            unordered_map<int,int> firstPos;
            firstPos.reserve(segEnd - segStart + 1);
            int pref = 0;
            firstPos[0] = segStart;        // prefix index before segment
            for (int j = segStart; j < segEnd; ++j) {
                if (s[j] == x) ++pref;
                else if (s[j] == y) --pref;   // s[j] must be x or y
                // prefix index after processing s[j] is j+1
                auto it = firstPos.find(pref);
                if (it != firstPos.end()) {
                    best = max(best, (j + 1) - it->second);
                } else {
                    firstPos[pref] = j + 1;
                }
            }
        }
        return best;
    }

    // 3) longest substring where #a = #b = #c
    int longestThreeEqual(const string& s) {
        int n = (int)s.size();
        unordered_map<long long, int> firstPos;
        firstPos.reserve(n * 2);
        int cntA = 0, cntB = 0, cntC = 0;
        auto encode = [&](int d1, int d2) -> long long {
            // shift by n to keep values non‑negative, then pack into 64‑bit
            long long key = ((long long)(d1 + n) << 32) | (unsigned int)(d2 + n);
            return key;
        };
        long long startKey = encode(0, 0);
        firstPos[startKey] = 0;               // empty prefix
        int best = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == 'a') ++cntA;
            else if (s[i] == 'b') ++cntB;
            else ++cntC;                       // 'c'
            int d1 = cntA - cntB;
            int d2 = cntA - cntC;
            long long key = encode(d1, d2);
            auto it = firstPos.find(key);
            if (it != firstPos.end()) {
                best = max(best, (i + 1) - it->second);
            } else {
                firstPos[key] = i + 1;
            }
        }
        return best;
    }

    int longestBalanced(string s) {
        int ans = 1;                         // at least one character exists
        ans = max(ans, longestRun(s));

        // two‑character cases
        ans = max(ans, longestTwoChars(s, 'a', 'b', 'c'));
        ans = max(ans, longestTwoChars(s, 'a', 'c', 'b'));
        ans = max(ans, longestTwoChars(s, 'b', 'c', 'a'));

        // three‑character case
        ans = max(ans, longestThreeEqual(s));

        return ans;
    }
};