class Solution:
    def decodeString(self, s: str) -> str:
        n = len(s)
        for i in range(n):
            if s[i] == '[':
                cnt = 1
                for j in range(i+1, n):
                    if s[j] == '[': cnt += 1
                    elif s[j] == ']': cnt -= 1
                    if cnt == 0:
                        k = i-1
                        while k >= 0 and s[k].isdigit(): k -= 1
                        return s[0:k+1] + int(s[k+1:i]) * self.decodeString(s[i+1:j]) + self.decodeString(s[j+1:])
        return s