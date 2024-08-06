class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        cnt = {}
        l = 0
        n = len(s)
        ans = 0
        for r in range(n):
            cnt[s[r]] = cnt.get(s[r], 0) + 1
            while cnt[s[r]] > 1:
                cnt[s[l]] -= 1
                l += 1
            ans = max(ans, r-l+1)
        return ans