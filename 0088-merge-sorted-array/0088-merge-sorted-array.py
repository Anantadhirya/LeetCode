class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        tmp = nums1.copy()[:m]
        i, j = 0, 0
        for k in range(m+n):
            b = False
            if i >= m: b = True
            elif j >= n: b = False
            else: b = nums2[j] < tmp[i]

            if b:
                nums1[k] = nums2[j]
                j += 1
            else:
                nums1[k] = tmp[i]
                i += 1
