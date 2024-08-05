class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        cnt = {}
        for i in nums:
            cnt[i] = cnt.get(i, 0) + 1
        n = len(nums)
        ans = [0, 0]
        for i, j in cnt.items():
            ans = max(ans, [j, i])
        return ans[1]