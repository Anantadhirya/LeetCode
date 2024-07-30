class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        m = ["", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"]
        n = len(digits)
        ans = [[] for _ in range(n+1)]
        ans[0].append("")
        for i in range(1,n+1):
            for j in ans[i-1]:
                for k in m[int(digits[i-1])]:
                    ans[i].append(j + k)
        return ans[n] if n != 0 else []