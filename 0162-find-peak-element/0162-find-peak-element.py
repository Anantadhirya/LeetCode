class Solution:
    def findPeakElement(self, nums: List[int]) -> int:
        n = len(nums)
        for i in range(n):
            if i-1 >= 0 and nums[i-1] >= nums[i]: continue
            if i+1 < n and nums[i+1] >= nums[i]: continue
            return i
        return -1