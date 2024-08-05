class Solution:
    def fullJustify(self, words: List[str], maxWidth: int) -> List[str]:
        lines = []
        width = []
        for i in words:
            if not lines or width[-1] + len(i) + 1 > maxWidth:
                lines.append([])
                width.append(-1)
            lines[-1].append(i)
            width[-1] += 1 + len(i)
        n = len(lines)
        for i in range(n-1):
            tmp = ""
            spaces = maxWidth - sum(len(word) for word in lines[i])
            gap = len(lines[i]) - 1
            for j in range(len(lines[i])):
                tmp += lines[i][j]
                if j < gap:
                    tmp += " " * (spaces//gap + (j < (spaces % gap)))
            tmp += " " * (maxWidth - len(tmp))
            lines[i] = tmp
        lines[-1] = " ".join(lines[-1])
        lines[-1] += " " * (maxWidth - len(lines[-1]))
        return lines