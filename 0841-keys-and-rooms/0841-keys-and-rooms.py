class Solution:
    def canVisitAllRooms(self, rooms: List[List[int]]) -> bool:
        n = len(rooms)
        vis = [0 for _ in range(n)]
        s = [0]
        while s:
            curr = s.pop()
            if vis[curr]: continue
            vis[curr] = 1
            for i in rooms[curr]:
                s.append(i)
        return all(vis)