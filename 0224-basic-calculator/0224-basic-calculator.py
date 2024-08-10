class Solution:
    def calculate(self, s: str) -> int:
        st = [""]
        for i in s:
            if i == "(": st.append("")
            elif i == ")":
                st[-2] += str(eval(st[-1]))
                st.pop()
            else: st[-1] += i
        return eval(st[0])