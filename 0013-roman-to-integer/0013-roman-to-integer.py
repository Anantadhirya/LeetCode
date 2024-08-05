class Solution:
    def romanToInt(self, s: str) -> int:
        m = {"I": 1, "V": 5, "X": 10, "L": 50, "C": 100, "D": 500, "M": 1000}
        v = []
        for i in s:
            if v and v[-1][0] == i:
                v[-1][1] += 1
            else: v.append([m[i], 1])
        n = len(v)
        ans = 0
        for i in range(n):
            if i+1 < n and v[i][0] < v[i+1][0]:
                ans -= v[i][0] * v[i][1]
            else:
                ans += v[i][0] * v[i][1]
        return ans