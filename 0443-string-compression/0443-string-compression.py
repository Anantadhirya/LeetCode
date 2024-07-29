class Solution:
    def compress(self, chars: List[str]) -> int:
        arr = []
        for i in chars:
            if len(arr) and arr[-1][0] == i:
                arr[-1][1] += 1
            else: arr.append([i, 1])
        ans = ""
        for i in arr:
            ans += i[0]
            if i[1] > 1: ans += str(i[1])
        chars.clear()
        for i in ans:
            chars.append(i)
        return len(chars)