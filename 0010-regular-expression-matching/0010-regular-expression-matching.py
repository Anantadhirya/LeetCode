class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        p2 = []
        for i in p:
            if p2 and p2[-1] == "*" and i == "*": continue
            p2.append(i)
        p = "".join(p2)
        return bool(re.compile(p).fullmatch(s))