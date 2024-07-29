class Solution:
    def reverseWords(self, s: str) -> str:
        arr = [""]
        for i in s:
            if i == " ":
                arr.append("")
            else:
                arr[-1] += i
        return " ".join([i for i in arr if len(i)][::-1])