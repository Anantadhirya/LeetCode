class Solution:
    def minFlips(self, a: int, b: int, c: int) -> int:
        ans = 0
        while a or b or c:
            if (c&1) and not ((a|b)&1):
                ans += 1
            if not (c&1) and ((a|b)&1):
                ans += (a&1) + (b&1)
            a //= 2
            b //= 2
            c //= 2
        return ans