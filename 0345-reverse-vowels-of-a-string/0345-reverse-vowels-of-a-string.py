class Solution:
    def reverseVowels(self, s: str) -> str:
        vowels = "aiueoAIUEO"
        tmp = [i for i in s if i in vowels]
        ans = ""
        for i in s:
            if i in vowels:
                ans += tmp[-1]
                tmp.pop()
            else: ans += i
        return ans