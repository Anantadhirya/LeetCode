class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        idx = 0
        n = len(t)
        for i in s:
            while idx < n and t[idx] != i:
                idx += 1
            if idx < n and t[idx] == i:
                idx += 1
                continue
            return False
        return True