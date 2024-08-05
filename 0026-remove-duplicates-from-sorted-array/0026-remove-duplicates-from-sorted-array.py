class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        tmp = nums.copy()
        vis = set()
        nums.clear()
        for i in tmp:
            if i in vis: continue
            nums.append(i)
            vis.add(i)
        return len(nums)