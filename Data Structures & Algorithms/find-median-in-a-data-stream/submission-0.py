class MedianFinder:
    from collections import heapq

    def __init__(self):
        self.left = []
        self.right = []

    def addNum(self, num: int) -> None:
        
        if not self.left and not self.right:
            self.left.append(-num)
            return

        if not self.right:
            if num > -self.left[0]:
                heapq.heappush(self.right, num)
                return
            else:
                n = -heapq.heappop(self.left)
                heapq.heappush(self.right, n)
                heapq.heappush(self.left, -num)
                return

        leftSize = len(self.left)
        rightSize = len(self.right)

        if leftSize == rightSize:
            if self.right and num > self.right[0]:
                # move right to left
                n = heapq.heappop(self.right)
                heapq.heappush(self.left, -n)
                heapq.heappush(self.right, num)
            elif self.left and num < -self.left[0]:
                # move left to right
                n = -heapq.heappop(self.left)
                heapq.heappush(self.right, n)
                heapq.heappush(self.left, -num)
            else:
                # falls in between, move to left, temporarily larger
                heapq.heappush(self.left, -num)
        else:
            if leftSize > rightSize:
                if -self.left[0] > num:
                    n = -heapq.heappop(self.left)
                    heapq.heappush(self.right, n)
                    heapq.heappush(self.left, -num)
                else:
                    heapq.heappush(self.right, num)

            else:
                if self.right[0] > num:
                    heapq.heappush(self.left, -num)
                else:
                    n = heapq.heappop(self.right)
                    heapq.heappush(self.left, -n)
                    heapq.heappush(self.right, num)


 

            
    def findMedian(self) -> float:
        # print(self.left)
        # print(self.right)
        leftSize = len(self.left)
        rightSize = len(self.right)

        total = leftSize + rightSize

        if total % 2 == 0:
            return (self.right[0] + -self.left[0]) / 2

        if leftSize > rightSize:
            return -self.left[0]

        return self.right[0]        


# Your MedianFinder object will be instantiated and called as such:
# obj = MedianFinder()
# obj.addNum(num)
# param_2 = obj.findMedian()