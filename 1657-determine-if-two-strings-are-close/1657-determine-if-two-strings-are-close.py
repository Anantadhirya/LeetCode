class Solution:
    def closeStrings(self, word1: str, word2: str) -> bool:
        cnt1, cnt2 = {}, {}
        for i in word1:
            cnt1[i] = cnt1.get(i, 0) + 1
        for i in word2:
            cnt2[i] = cnt2.get(i, 0) + 1
        return sorted(cnt1.keys()) == sorted(cnt2.keys()) and sorted(cnt1.values()) == sorted(cnt2.values())