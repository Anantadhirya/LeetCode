class Solution:
    def minimumPushes(self, word: str) -> int:
        cnt = Counter(word)
        v = sorted(cnt.values())
        n = len(v)
        ans = 0
        for i in range(n):
            ans += v[n-1-i] * (1 + i//8)
        return ans