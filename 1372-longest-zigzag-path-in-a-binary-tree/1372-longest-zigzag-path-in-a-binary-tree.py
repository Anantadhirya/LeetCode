# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def longestZigZag(self, root: Optional[TreeNode]) -> int:
        ans = 0
        def dfs(curr):
            if not curr: return
            dfs(curr.left)
            dfs(curr.right)
            curr.r = 1 + curr.right.l if curr.right else 0
            curr.l = 1 + curr.left.r if curr.left else 0
            nonlocal ans
            ans = max(ans, curr.r, curr.l)
        
        dfs(root)
        return ans