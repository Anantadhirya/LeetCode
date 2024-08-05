class Solution:
    def canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int:
        ans = 0
        sm = 0
        tmp = 0
        n = len(gas)
        for i in range(n):
            sm += gas[i] - cost[i]
            tmp += gas[i] - cost[i]
            if tmp < 0:
                tmp = 0
                ans = (i+1) % n
        return ans if sm >= 0 else -1