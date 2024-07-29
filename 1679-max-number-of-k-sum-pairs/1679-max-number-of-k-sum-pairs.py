class Solution:
    def maxOperations(self, nums: List[int], k: int) -> int:
        nums.sort()
        n = len(nums)
        ans = 0
        j = n-1
        for i in range(len(nums)):
            while j > i and nums[i] + nums[j] > k:
                j -= 1
            if i < j and nums[i] + nums[j] == k:
                ans += 1
                j -= 1
        return ans