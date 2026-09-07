class Solution:
    def maxArea(self, heights: List[int]) -> int:
        start, end = 0, len(heights) - 1
        maxArea = 0
        while start < end:
            w = end - start
            h = min(heights[start], heights[end])
            maxArea = max(maxArea, w * h)
            h1, h2 = heights[start], heights[end]
            if h1 > h2:
                end -= 1
            elif h2 > h1:
                start += 1
            else:
                end -= 1
                start += 1

        return maxArea
