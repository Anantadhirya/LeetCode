class Solution:
    def reverse(self, x: int) -> int:
        ret = int(str(abs(x))[::-1])
        if x < 0: ret *= -1
        if not -2**31 <= ret <= 2**31 - 1: return 0
        return ret