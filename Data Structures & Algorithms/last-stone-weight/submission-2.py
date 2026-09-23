class Solution:
    def lastStoneWeight(self, stones: list[int]) -> int:
        import heapq
        h = []
        for s in stones:
            heapq.heappush(h, -s)

        while len(h) > 1:
            s1 = -heapq.heappop(h)
            s2 = -heapq.heappop(h)

            if s1 == s2:
                continue
            else:
                s1 -= s2
                heapq.heappush(h, -s1)

        if h:
            return -h[0]
        else:
            return 0