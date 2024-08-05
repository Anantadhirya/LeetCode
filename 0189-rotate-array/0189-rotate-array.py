class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        tmp = nums.copy()
        n = len(nums)
        for i in range(n):
            nums[i] = tmp[((i-k)%n+n)%n]