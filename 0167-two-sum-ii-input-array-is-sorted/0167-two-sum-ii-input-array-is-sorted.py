class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        n = len(numbers)
        r = n-1
        for l in range(n):
            while numbers[l] + numbers[r] > target:
                r -= 1
            if numbers[l] + numbers[r] == target:
                return [l+1, r+1]
        return None