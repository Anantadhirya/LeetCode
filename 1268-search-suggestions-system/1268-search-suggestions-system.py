class Solution(object):
    def suggestedProducts(self, products, searchWord):
        """
        :type products: List[str]
        :type searchWord: str
        :rtype: List[List[str]]
        """
        products.sort()
        n = len(searchWord)
        ans = [[] for _ in range(n)]
        for i in range(n):
            idx = bisect_left(products, searchWord[:i+1])
            for j in range(3):
                if idx+j < len(products) and i < len(products[idx+j]) and products[idx+j][:i+1] == searchWord[:i+1]:
                    ans[i].append(products[idx+j])
        return ans