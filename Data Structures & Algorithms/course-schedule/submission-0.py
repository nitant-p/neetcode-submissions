class Solution:
    def canFinish(self, numCourses: int, prerequisites: list[list[int]]) -> bool:
        from collections import deque
        nextt = {}
        indegree = [0] * numCourses
        for c, p in prerequisites:
            if p not in nextt:
                nextt[p] = []
            nextt[p].append(c)
            indegree[c] += 1

        dq = deque([])    
        for i in range(len(indegree)):
            if indegree[i] == 0:
                dq.append(i)

        completed = 0
        while dq:
            course = dq.popleft()
            completed += 1
            if course in nextt:
                neigh = nextt[course]
                for n in neigh:
                    indegree[n] -= 1
                    if indegree[n] == 0:
                        dq.append(n)

        return completed == numCourses
            