class Solution(object):
    def lengthOfLongestSubstring(self, s):
        st = set()
        l = 0
        m = 0

        for r in range(len(s)):
            while s[r] in st:
                st.remove(s[l])
                l += 1

            st.add(s[r])
            m = max(m, r - l + 1)

        return m