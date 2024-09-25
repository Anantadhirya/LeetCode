class Solution:
    def sumPrefixScores(self, words: List[str]) -> List[int]:
        cnt = {}
        tmp = ""
        for word in words:
            tmp = word
            while len(tmp):
                cnt[tmp] = cnt.get(tmp, 0) + 1
                tmp = tmp[:-1]
        ans = []
        for word in words:
            ans.append(0)
            tmp = word
            while len(tmp):
                ans[-1] += cnt[tmp]
                tmp = tmp[:-1]
        return ans