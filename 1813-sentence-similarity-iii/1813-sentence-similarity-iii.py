class Solution:
    def areSentencesSimilar(self, sentence1: str, sentence2: str) -> bool:
        s1 = sentence1.split()
        s2 = sentence2.split()
        if len(s1) > len(s2):
            s1, s2 = s2, s1
        for i in range(len(s1)):
            if s1[i] != s2[i]:
                return s1[i:] == s2[-(len(s1) - i):]
        return True