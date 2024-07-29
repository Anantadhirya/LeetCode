# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def dfs(self, curr, targetSum, prefSum = 0):
        if not curr: return
        prefSum += curr.val
        self.ans += self.m.get(prefSum - targetSum, 0)
        self.m[prefSum] = self.m.get(prefSum, 0) + 1
        self.dfs(curr.left, targetSum, prefSum)
        self.dfs(curr.right, targetSum, prefSum)
        self.m[prefSum] -= 1
        
    def pathSum(self, root: Optional[TreeNode], targetSum: int) -> int:
        self.ans = 0
        self.m = {0: 1}
        self.dfs(root, targetSum)
        return self.ans
        
        