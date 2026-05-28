class Solution:
    def stringIndices(self, wordsContainer: List[str], wordsQuery: List[str]) -> List[int]:
        index = -1
        root = {}
        for i, word in enumerate(wordsContainer):
            if index == -1 or len(word) < len(wordsContainer[index]):
                index = i
            curr = root
            for c in reversed(word):
                if c not in curr:
                    curr[c] = {}
                curr = curr[c]
                if '*' not in curr or len(word) < len(wordsContainer[curr['*']]):
                    curr['*'] = i
        res = []
        for query in wordsQuery:
            curr = root
            idx = index
            for c in reversed(query):
                if c not in curr:
                    break
                curr = curr[c]
                idx = curr['*']
            res.append(idx)
        return res