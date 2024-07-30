class Solution:
    def minReorder(self, n: int, connections: List[List[int]]) -> int:
        adj = [[] for _ in range(n)]
        for u, v in connections:
            adj[u].append((v, 1))
            adj[v].append((u, 0))
        
        self.ans = 0
        def dfs(curr, par):
            for to, v in adj[curr]:
                if to == par: continue
                self.ans += v
                dfs(to, curr)
        dfs(0, -1)
        return self.ans