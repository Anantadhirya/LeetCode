class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        ans = max(piles)
        l, r = 1, ans
        while l <= r:
            mid = (l+r)//2
            hour = 0
            for i in piles:
                hour += ceil(i/mid)
            if hour <= h:
                ans = mid
                r = mid - 1
            else: l = mid + 1
        return ans