class Solution:
    def findOrder(self, numCourses: int, prerequisites: list[list[int]]) -> list[int]:
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

        order = []
        while dq:
            course = dq.popleft()
            order.append(course)
            if course in nextt:
                neigh = nextt[course]
                for n in neigh:
                    indegree[n] -= 1
                    if indegree[n] == 0:
                        dq.append(n)

        if len(order) == numCourses:
            return order
        else:
            return []