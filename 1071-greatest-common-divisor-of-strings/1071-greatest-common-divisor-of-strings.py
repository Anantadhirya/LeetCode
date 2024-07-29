class Solution:
    def gcdOfStrings(self, str1: str, str2: str) -> str:
        def divides(str1, str2):
            if len(str2) % len(str1) != 0: return 0
            for i in range(len(str2)):
                if str2[i] != str1[i % len(str1)]: return 0
            return 1
        ans = ""
        tmp = ""
        for i in range(min(len(str1), len(str2))):
            if str1[i] == str2[i]:
                tmp += str1[i]
                if divides(tmp, str1) and divides(tmp, str2):
                    ans = tmp
            else: break
        return ans