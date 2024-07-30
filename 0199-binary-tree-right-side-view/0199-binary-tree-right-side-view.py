# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
        ret = []
        def dfs(curr, depth = 0):
            if not curr: return
            if depth >= len(ret): ret.append(0)
            ret[depth] = curr.val
            dfs(curr.left, depth + 1)
            dfs(curr.right, depth + 1)
        dfs(root)
        return ret