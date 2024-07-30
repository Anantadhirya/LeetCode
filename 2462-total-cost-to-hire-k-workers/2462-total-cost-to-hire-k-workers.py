class Solution:
    def totalCost(self, costs: List[int], k: int, candidates: int) -> int:
        n = len(costs)
        h = [[costs[i], i] for i in range(n) if i < candidates or i >= n - candidates]
        heapify(h)
        l, r = candidates, n-candidates-1
        hapus = [0 for _ in costs]
        ans = 0
        
        for _ in range(k):
            cost, idx = heappop(h)
            ans += cost
            hapus[idx] = 1
            if l <= r:
                if idx < l:
                    heappush(h, [costs[l], l])
                    l += 1
                else:
                    heappush(h, [costs[r], r])
                    r -= 1
                    
        return ans