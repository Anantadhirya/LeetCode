class Solution:
    def numberToWords(self, num: int) -> str:
        if num == 0: return "Zero"
        s = str(num)
        m = ["", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"]
        m2 = ["", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"]
        def solve(s):
            ret = []
            if len(s) >= 3 and s[-3] != '0':
                ret.append(m[int(s[-3])] + " Hundred")
            if len(s) >= 2 and s[-2] == '1':
                ret.append(m[int(s[-2:])])
            else:
                if len(s) >= 2 and s[-2] != '0':
                    ret.append(m2[int(s[-2])])
                if len(s) >= 1 and s[-1] != '0':
                    ret.append(m[int(s[-1])])
            return " ".join(ret)
        ans = []
        if len(s) <= 3 or s[-3:] != "000": ans.append(solve(s))
        if len(s) > 3:
            s = s[:-3]
            if s[-3:] != "000": ans.append(solve(s) + " Thousand")
        if len(s) > 3:
            s = s[:-3]
            if s[-3:] != "000": ans.append(solve(s) + " Million")
        if len(s) > 3:
            s = s[:-3]
            if s[-3:] != "000": ans.append(solve(s) + " Billion")
        return " ".join(ans[::-1])