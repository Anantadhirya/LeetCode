class Solution:
    def subdomainVisits(self, cpdomains: List[str]) -> List[str]:
        ans = {}
        for s in cpdomains:
            spl = s.split(" ")
            count = int(spl[0])
            domains = spl[1].split(".")
            for i in range(len(domains)):
                d = ".".join(domains[i:])
                ans[d] = ans.get(d, 0) + count
        return [f"{c} {d}" for d, c in ans.items()]