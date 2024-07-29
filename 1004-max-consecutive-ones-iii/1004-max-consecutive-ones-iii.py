class Solution:
    def longestOnes(self, nums: List[int], k: int) -> int:
        n = len(nums)
        l = 0
        cnt, ans = 0, 0
        for r in range(n):
            cnt += (nums[r] == 0)
            while cnt > k:
                cnt -= (nums[l] == 0)
                l += 1
            ans = max(ans, r-l+1)
        return ans