class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        numSet = set()
        for n in nums:
            numSet.add(n)

        maxx = 0
        for n in numSet:
            if n - 1 not in numSet:
                # beginning
                x = n
                length = 0
                while x in numSet:
                    length += 1
                    maxx = max(maxx, length)
                    x += 1
        
        return maxx