class Solution:
    def candy(self, ratings: List[int]) -> int:
        n = len(ratings)
        v = [(ratings[i], i) for i in range(n)]
        v.sort()
        ans = [0 for _ in range(n)]
        for _, i in v:
            ans[i] = 1
            if i-1 >= 0 and ratings[i-1] < ratings[i]:
                ans[i] = max(ans[i], ans[i-1] + 1)
            if i+1 < n and ratings[i] > ratings[i+1]:
                ans[i] = max(ans[i], ans[i+1] + 1)
        return sum(ans)