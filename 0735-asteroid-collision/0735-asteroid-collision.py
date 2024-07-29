class Solution:
    def asteroidCollision(self, asteroids: List[int]) -> List[int]:
        ans = []
        for i in asteroids:
            tambah = 1
            while tambah and len(ans) and ans[-1] > 0 and i < 0:
                if ans[-1] > -i: tambah = 0
                elif ans[-1] < -i: ans.pop()
                else:
                    tambah = 0
                    ans.pop()
            if tambah: ans.append(i)
        return ans