# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxLevelSum(self, root: Optional[TreeNode]) -> int:
        level = []
        def dfs(curr, depth):
            if not curr: return
            if depth >= len(level): level.append(0)
            level[depth] += curr.val
            dfs(curr.left, depth + 1)
            dfs(curr.right, depth + 1)
        dfs(root, 0)
        ans = [inf, 0]
        for i in range(len(level)):
            ans = min(ans, [-level[i], i+1])
        return ans[1]