# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isSubtree(self, root: TreeNode | None, subRoot: TreeNode | None) -> bool:
        def sameTree(a, b):
            if not a:
                return b is None

            if not b:
                return a is None

            if a.val == b.val:
                return sameTree(a.left, b.left) and sameTree(a.right, b.right)
            else:
                return False


        def dfs(node, sub):
            if not node:
                return False
            
            if sameTree(node, sub):
                return True
            else:
                return dfs(node.left, sub) or dfs(node.right, sub)

        return dfs(root, subRoot)