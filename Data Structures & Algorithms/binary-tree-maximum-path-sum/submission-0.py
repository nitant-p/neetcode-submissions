# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxPathSum(self, root: TreeNode | None) -> int:
        maxx = float('-inf')
        def dfs(node):
            nonlocal maxx
            if not node:
                return 0
            
            l = dfs(node.left)
            r = dfs(node.right)

            maxx = max(maxx, l + node.val, r + node.val, l + r + node.val, node.val)
            return max(l + node.val, r + node.val, node.val)

        dfs(root)
        return maxx
