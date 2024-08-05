class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        tmp = [i for i in nums if i != val]
        n = len(tmp)
        for i in range(n):
            nums[i] = tmp[i]
        return n