class Solution:
    def longestSubarray(self, nums: List[int]) -> int:
        n = len(nums)
        cnt, ans = 0, 0
        l = 0
        for r in range(n):
            cnt += (nums[r] == 0)
            while cnt > 1:
                cnt -= (nums[l] == 0)
                l += 1
            ans = max(ans, r-l)
        return ans