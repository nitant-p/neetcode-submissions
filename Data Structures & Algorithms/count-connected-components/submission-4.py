class Solution:
    def countComponents(self, n: int, edges: list[list[int]]) -> int:
        from collections import deque

        graph = {}
        for a,b in edges:
            if a not in graph:
                graph[a] = []
            graph[a].append(b)
            if b not in graph:
                graph[b] = []
            graph[b].append(a)

        visited = set()

        for i in range(n):
            if i not in graph:
                graph[i] = set()

        components = 0

        for node, _ in graph.items():
            if node not in visited:
                components += 1
                dq = deque([])
                dq.append(node)
                while dq:
                    node = dq.popleft()
                    for n in graph[node]:
                        if n not in visited:
                            dq.append(n)
                            visited.add(n)

        return components

