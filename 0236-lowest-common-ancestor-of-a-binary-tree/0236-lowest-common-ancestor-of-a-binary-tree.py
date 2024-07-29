# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        self.ans = None
        def dfs(curr):
            if not curr: return
            if self.ans: return
            dfs(curr.left)
            dfs(curr.right)
            if self.ans: return
            curr.m = (curr.val == p.val) + 2*(curr.val == q.val)
            if curr.left: curr.m |= curr.left.m
            if curr.right: curr.m |= curr.right.m
            if curr.m == 3:
                self.ans = curr
        dfs(root)
        return self.ans