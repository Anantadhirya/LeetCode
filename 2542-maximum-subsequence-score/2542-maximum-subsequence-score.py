class Solution:
    def maxScore(self, nums1: List[int], nums2: List[int], k: int) -> int:
        arr = sorted([(b, a) for a, b in zip(nums1, nums2)])
        n = len(arr)
        ans, tmp = 0, 0
        h = []
        for i in range(n-1, -1, -1):
            tmp += arr[i][1]
            heappush(h, arr[i][1])
            if len(h) > k: tmp -= heappop(h)
            if len(h) == k: ans = max(ans, arr[i][0] * tmp)
        return ans