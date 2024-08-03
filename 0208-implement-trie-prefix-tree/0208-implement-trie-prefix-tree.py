class Trie:

    def __init__(self):
        self.s = False
        self.adj = {}

    def insert(self, word: str) -> None:
        curr = self
        for i in word:
            if i not in curr.adj:
                curr.adj[i] = Trie()
            curr = curr.adj[i]
        curr.s = True

    def search(self, word: str) -> bool:
        curr = self
        for i in word:
            if i not in curr.adj:
                return False
            curr = curr.adj[i]
        return curr.s

    def startsWith(self, prefix: str) -> bool:
        curr = self
        for i in prefix:
            if i not in curr.adj:
                return False
            curr = curr.adj[i]
        return True
        


# Your Trie object will be instantiated and called as such:
# obj = Trie()
# obj.insert(word)
# param_2 = obj.search(word)
# param_3 = obj.startsWith(prefix)