class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        n = len(nums)
        l = 0
        tmp = 0
        ans = inf
        for r in range(n):
            tmp += nums[r]
            while tmp - nums[l] >= target:
                tmp -= nums[l]
                l += 1
            if tmp >= target:
                ans = min(ans, r-l+1)
        return ans if ans != inf else 0