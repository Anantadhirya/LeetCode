class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        n = len(nums)
        i = 0
        cnt = {}
        for j in range(n):
            if cnt.get(nums[j], 0) >= 2: continue
            cnt[nums[j]] = cnt.get(nums[j], 0) + 1
            nums[i], nums[j] = nums[j], nums[i]
            i += 1
        return i