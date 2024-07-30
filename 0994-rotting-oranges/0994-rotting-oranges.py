class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        n = len(grid)
        m = len(grid[0])
        dist = [[inf for j in range(m)] for i in range(n)]
        q = deque()
        for i in range(n):
            for j in range(m):
                if grid[i][j] == 2:
                    dist[i][j] = 0
                    q.append([i, j])
        
        def inside(i, j):
            return 0 <= i < n and 0 <= j < m
        dx = [1, -1, 0, 0]
        dy = [0, 0, 1, -1]
        while q:
            i, j = q[0]
            q.popleft()
            for x, y in zip(dx, dy):
                if inside(i+x, j+y) and grid[i+x][j+y] and dist[i+x][j+y] == inf:
                    dist[i+x][j+y] = dist[i][j] + 1
                    q.append([i+x, j+y])
        ans = 0
        for i in range(n):
            for j in range(m):
                if grid[i][j]:
                    ans = max(ans, dist[i][j])
        return ans if ans != inf else -1