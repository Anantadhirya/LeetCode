class Solution:
    def uniqueOccurrences(self, arr: List[int]) -> bool:
        cnt = {}
        for i in arr:
            cnt[i] = cnt.get(i, 0) + 1
        v = [i for i in cnt.values()]
        return len(v) == len(set(v))