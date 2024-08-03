class Solution:
    def findMissingAndRepeatedValues(self, grid: List[List[int]]) -> List[int]:
        cnt = {}
        n = len(grid)
        for row in grid:
            for i in row:
                cnt[i] = cnt.get(i, 0) + 1
        a, b = 0, 0
        for i in range(1, n*n+1):
            if i not in cnt: b = i
            elif cnt[i] == 2: a = i
        return [a, b]