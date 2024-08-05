class Solution:
    def hIndex(self, citations: List[int]) -> int:
        citations.sort()
        n = len(citations)
        ans = 0
        for i in range(1, n+1):
            if citations[-i] >= i:
                ans = i
        return ans