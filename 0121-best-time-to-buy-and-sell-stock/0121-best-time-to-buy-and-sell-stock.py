class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        sell = 0
        ans = 0
        for i in prices[::-1]:
            sell = max(sell, i)
            ans = max(ans, sell - i)
        return ans