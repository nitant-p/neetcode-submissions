class Solution:
    def climbStairs(self, n: int) -> int:
        if n < 3:
            return n
        ways = [float('inf')] * (n + 1)
        ways[0] = 1
        ways[1] = 1
        ways[2] = 2
        for i in range(3, n + 1):
            ways[i] = ways[i - 1] + ways[i - 2]

        return ways[n]