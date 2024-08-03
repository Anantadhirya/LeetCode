class Solution:
    def largestAltitude(self, gain: List[int]) -> int:
        ans, tmp = 0, 0
        for i in gain:
            tmp += i
            ans = max(ans, tmp)
        return ans