class Solution(object):
    def eraseOverlapIntervals(self, intervals):
        """
        :type intervals: List[List[int]]
        :rtype: int
        """
        intervals.sort()
        n = len(intervals)
        dp = [inf for _ in range(n+1)]
        dp[n] = 0
        for i in range(n-1, -1, -1):
            l, r = intervals[i]
            idx = bisect_left(intervals, [r, -inf])
            dp[i] = min(dp[i+1] + 1, dp[idx] + idx - i - 1)
        return dp[0]
        