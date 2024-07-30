class SmallestInfiniteSet:

    def __init__(self):
        self.h = [i+1 for i in range(2000)]
        self.ada = [True for i in range(2000)]

    def popSmallest(self) -> int:
        ret = heappop(self.h)
        self.ada[ret] = False
        return ret

    def addBack(self, num: int) -> None:
        if not self.ada[num]:
            heappush(self.h, num)
            self.ada[num] = True


# Your SmallestInfiniteSet object will be instantiated and called as such:
# obj = SmallestInfiniteSet()
# param_1 = obj.popSmallest()
# obj.addBack(num)