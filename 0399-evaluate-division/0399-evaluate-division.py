class Solution:
    def calcEquation(self, equations: List[List[str]], values: List[float], queries: List[List[str]]) -> List[float]:
        n = 0
        m = {}
        for a, b in equations:
            if a not in m:
                m[a] = n
                n += 1
            if b not in m:
                m[b] = n
                n += 1
        mat = [[(1 if i == j else -1) for j in range(n)] for i in range(n)]
        
        for [a, b], v in zip(equations, values):
            mat[m[a]][m[b]] = v
            mat[m[b]][m[a]] = 1/v
        
        for k in range(n):
            for i in range(n):
                for j in range(n):
                    if mat[i][k] == -1 or mat[k][j] == -1: continue
                    if mat[i][j] == -1:
                        mat[i][j] = mat[i][k] * mat[k][j]
        return [mat[m[a]][m[b]] if a in m and b in m else -1.0 for a, b in queries]