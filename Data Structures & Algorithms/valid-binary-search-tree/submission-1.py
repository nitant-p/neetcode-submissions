# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        def dfs(node, maxx, minn):
            if not node:
                return True
            else:
                l = node.left
                r = node.right
                if l:
                    if l.val >= node.val or l.val >= maxx or l.val <= minn:
                        return False

                if r:
                    if r.val <= node.val or r.val <= minn or r.val >= maxx:
                        return False

                return dfs(node.left, node.val, minn) and dfs(node.right, maxx, node.val)


        return dfs(root, float('inf'), float('-inf'))
        