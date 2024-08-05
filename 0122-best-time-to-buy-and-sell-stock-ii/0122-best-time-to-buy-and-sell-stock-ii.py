class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        buy = -inf
        sell = 0
        for i in prices:
            sell, buy = max(sell, buy + i), max(buy, sell - i)
        return sell