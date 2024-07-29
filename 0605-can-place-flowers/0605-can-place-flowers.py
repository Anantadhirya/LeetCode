class Solution:
    def canPlaceFlowers(self, flowerbed: List[int], n: int) -> bool:
        for i in range(len(flowerbed)):
            if flowerbed[i]: continue
            if i-1 >= 0 and flowerbed[i-1]: continue
            if i+1 < len(flowerbed) and flowerbed[i+1]: continue
            n -= 1
            flowerbed[i] = 1
        return n <= 0