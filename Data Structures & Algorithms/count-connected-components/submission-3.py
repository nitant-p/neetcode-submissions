class Solution:
    def countComponents(self, n: int, edges: list[list[int]]) -> int:
        graph = {}

        for a, b in edges:
            if a not in graph:
                graph[a] = []
            if b not in graph:
                graph[b] = []

            graph[a].append(b)
            graph[b].append(a)

        for i in range(n):
            if i not in graph:
                graph[i] = []

        visited = set()
        components = 0

        def dfs(node):
            visited.add(node)

            for neigh in graph[node]:
                if neigh not in visited:
                    dfs(neigh)

        for node in graph:
            if node not in visited:
                components += 1
                dfs(node)

        return components