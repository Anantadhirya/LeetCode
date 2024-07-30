# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def deleteNode(self, root: Optional[TreeNode], key: int) -> Optional[TreeNode]:
        if not root: return None
        if key < root.val: root.left = self.deleteNode(root.left, key)
        elif key > root.val: root.right = self.deleteNode(root.right, key)
        elif key == root.val:
            def merge(a, b):
                if not a and not b: return None
                if not a: return b
                if not b: return a
                if a.val < b.val:
                    a.right = merge(a.right, b)
                else:
                    a.left = merge(a.left, b)
                return a
            if root.right: 
                root.right.left = merge(root.left, root.right.left)
                root = root.right
            else: root = root.left
        return root