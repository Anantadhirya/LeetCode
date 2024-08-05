class Solution:
    def convert(self, s: str, numRows: int) -> str:
        ans = ["" for _ in range(numRows)]
        j = 0
        d = 1
        if numRows == 1: return s
        for i in s:
            ans[j] += i
            j += d
            if j == numRows-1 or j == 0: d *= -1
        return "".join(ans)