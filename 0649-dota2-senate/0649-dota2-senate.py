class Solution:
    def predictPartyVictory(self, senate: str) -> str:
        n = len(senate)
        r = deque([i for i in range(n) if senate[i] == "R"])
        d = deque([i for i in range(n) if senate[i] == "D"])
        deleted = [False for _ in range(n)]
        while r or d:
            for i in range(n):
                if deleted[i]: continue
                if senate[i] == "R":
                    if not d: return "Radiant"
                    deleted[d.popleft()] = True
                    r.append(r.popleft())
                else:
                    if not r: return "Dire"
                    deleted[r.popleft()] = True
                    d.append(d.popleft())
        return ""