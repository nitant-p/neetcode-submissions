"""
# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []
"""

from typing import Optional
class Solution:
    def cloneGraph(self, node: Optional['Node']) -> Optional['Node']:
        if not node:
            return None

        if not node.neighbors:
            return Node(1)

        from collections import deque
        dq = deque([])

        dq.append(node)

        visited = set()
        edges = []
        while dq:
            curr = dq.popleft()
            if curr.val in visited:
                continue
            # print(curr.val)
            visited.add(curr.val)

            for neigh in curr.neighbors:
                dq.append(neigh)
                edges.append([curr.val, neigh.val])


        # print("ypppp")
        nToNode = {}

        for a,b in edges:
            if a not in nToNode:
                aNode = Node(a)
                nToNode[a] = aNode
            else:
                aNode = nToNode[a]

            if b not in nToNode:
                bNode = Node(b)
                nToNode[b] = bNode
            else:
                bNode = nToNode[b]
            
            aNode.neighbors.append(bNode)
            # bNode.neighbors.append(aNode)

        # for n, node in nToNode.items():
        #     print(f"n: {n}")
        #     print(f"node: {node}")

        return nToNode[1]
