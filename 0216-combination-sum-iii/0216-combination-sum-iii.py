class Solution:
    def combinationSum3(self, k: int, n: int) -> List[List[int]]:
        ans = []
        tmp = []
        def bf():
            nonlocal tmp
            nonlocal ans
            if len(tmp) == k:
                if sum(tmp) == n:
                    ans.append(tmp.copy())
                return
            mx = 0
            if tmp: mx = max(tmp)
            for i in range(mx+1, 10):
                tmp.append(i)
                bf()
                tmp.pop()
        bf()
        return ans