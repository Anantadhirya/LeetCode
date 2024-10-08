class Solution:
    def maxProfit(self, prices: List[int], fee: int) -> int:
        n = len(prices)
        buy = -inf
        sell = 0
        for i in prices:
            buy = max(buy, sell - i)
            sell = max(sell, buy + i - fee)
        return sell