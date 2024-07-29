class Solution:
    def pivotIndex(self, nums: List[int]) -> int:
        n = len(nums)
        for i in range(1, n):
            nums[i] += nums[i-1]
        for i in range(n):
            l = nums[i-1] if i-1 >= 0 else 0
            r = nums[-1] - nums[i]
            if l == r: return i
        return -1