class Solution:
    def findDifference(self, nums1: List[int], nums2: List[int]) -> List[List[int]]:
        s1 = {i for i in nums1}
        s2 = {i for i in nums2}
        ans1 = [i for i in s1 if i not in s2]
        ans2 = [i for i in s2 if i not in s1]
        return [ans1, ans2]