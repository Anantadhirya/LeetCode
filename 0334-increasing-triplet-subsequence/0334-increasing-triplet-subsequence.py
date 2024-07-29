class Solution:
    def increasingTriplet(self, nums: List[int]) -> bool:
        a = inf
        b = inf
        for i in nums:
            if b < i: return 1
            if a < i:
                b = min(b, i)
            a = min(a, i)
        return 0