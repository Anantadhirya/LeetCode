class Solution:
    def findCircleNum(self, isConnected: List[List[int]]) -> int:
        n = len(isConnected)
        par = [i for i in range(n)]
        
        def fp(i):
            if par[i] == i: return i
            par[i] = fp(par[i])
            return par[i]
        def join(u, v):
            u = fp(u)
            v = fp(v)
            par[u] = v
        
        for i in range(n):
            for j in range(n):
                if isConnected[i][j]:
                    join(i, j)
        
        return sum([fp(i) == i for i in range(n)])