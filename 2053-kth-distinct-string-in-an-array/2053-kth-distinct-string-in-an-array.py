class Solution:
    def kthDistinct(self, arr: List[str], k: int) -> str:
        cnt = {}
        for i in arr:
            cnt[i] = cnt.get(i, 0) + 1
        d = [i for i in arr if cnt[i] == 1]
        return d[k-1] if k-1 < len(d) else ""