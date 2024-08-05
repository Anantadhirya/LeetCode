class Solution:
    def intToRoman(self, num: int) -> str:
        s = [int(i) for i in str(num)]
        n = len(s)
        ans = ""
        if n >= 4:
            ans += "M" * s[-4]
        if n >= 3:
            if s[-3] == 4: ans += "CD"
            elif s[-3] == 9: ans += "CM"
            else:
                if s[-3] >= 5: ans += "D"
                ans += "C" * (s[-3] % 5)
        if n >= 2:
            if s[-2] == 4: ans += "XL"
            elif s[-2] == 9: ans += "XC"
            else:
                if s[-2] >= 5: ans += "L"
                ans += "X" * (s[-2] % 5)
        if n >= 1:
            if s[-1] == 4: ans += "IV"
            elif s[-1] == 9: ans += "IX"
            else:
                if s[-1] >= 5: ans += "V"
                ans += "I" * (s[-1] % 5)
        return ans