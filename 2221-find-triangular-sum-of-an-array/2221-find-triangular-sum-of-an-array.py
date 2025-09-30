@cache
def C(n, k):
    if k == 0: return 1
    if n <= 0: return 0
    return C(n-1, k-1) + C(n-1, k) % 10

class Solution:
    def triangularSum(self, nums: List[int]) -> int:
        n = len(nums)
        ans = 0
        for i in range(n):
            ans += nums[i] * C(n-1, i) % 10
            ans %= 10
        return ans