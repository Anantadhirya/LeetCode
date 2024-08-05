class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        n = min(len(i) for i in strs)
        for i in range(1,n+1)[::-1]:
            if all(s[:i] == strs[0][:i] for s in strs):
                return strs[0][:i]
        return ""