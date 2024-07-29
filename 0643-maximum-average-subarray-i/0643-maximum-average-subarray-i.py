class Solution:
    def findMaxAverage(self, nums: List[int], k: int) -> float:
        n = len(nums)
        for i in range(1, n):
            nums[i] += nums[i-1]
        ans = nums[k-1]
        for i in range(k, n):
            ans = max(ans, nums[i] - nums[i-k])
        return ans / k