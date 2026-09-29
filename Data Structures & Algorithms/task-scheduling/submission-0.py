class Solution:
    def leastInterval(self, tasks: list[str], n: int) -> int:
        import heapq
        counts = {}
    
        for t in tasks:
            if t in counts:
                counts[t] += 1
            else:
                counts[t] = 1

        h = []
        for t,c in counts.items():
            heapq.heappush(h, (-c, t))

        total = 0
        while h:
            q = []
            while h and len(q) < n + 1:
                q.append(heapq.heappop(h))

            total += n + 1
            processing = len(q)
            while q:
                count, task = q[-1]
                if count < -1:
                    heapq.heappush(h, (count + 1, task))
                q.pop()

            
            if not h:
                total = total - (n + 1 - processing)

            

        return total
