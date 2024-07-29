class Solution:
    def equalPairs(self, grid: List[List[int]]) -> int:
        n = len(grid)
        ans = 0
        for i in range(n):
            for j in range(n):
                sama = 1
                for k in range(n):
                    if grid[i][k] != grid[k][j]:
                        sama = 0
                        break
                ans += sama
        return ans