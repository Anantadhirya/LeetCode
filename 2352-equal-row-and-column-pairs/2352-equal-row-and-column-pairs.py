class Solution:
    def equalPairs(self, grid: List[List[int]]) -> int:
        n = len(grid)
        ans = 0
        m = {}
        t = ()
        for row in grid:
            t = tuple(row)
            m[t] = m.get(t, 0) + 1
        for col in zip(*grid):
            t = tuple(col)
            ans += m.get(t, 0)
        return ans