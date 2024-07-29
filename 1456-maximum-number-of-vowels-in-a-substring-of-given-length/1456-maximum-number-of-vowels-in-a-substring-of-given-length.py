class Solution:
    def maxVowels(self, s: str, k: int) -> int:
        ans = 0
        tmp = 0
        n = len(s)
        vowels = "aiueo"
        for i in range(k):
            tmp += (s[i] in vowels)
        ans = tmp
        for i in range(k, n):
            if s[i] in vowels: tmp += 1
            if s[i-k] in vowels: tmp -= 1
            ans = max(ans, tmp)
        return ans