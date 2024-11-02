class Solution:
    def isCircularSentence(self, sentence: str) -> bool:
        s = sentence.split()
        n = len(s)
        for i in range(n):
            if s[i][-1] != s[(i+1)%n][0]: return False
        return True