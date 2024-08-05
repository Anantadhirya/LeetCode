class Solution:
    def jump(self, nums: List[int]) -> int:
        n = len(nums)
        dp = [inf for _ in range(n)]
        dp[0] = 0
        j = 1
        for i in range(n):
            if dp[i] == inf: continue
            while j < n and j <= i + nums[i]:
                dp[j] = dp[i] + 1
                j += 1
        print(dp)
        return dp[-1]