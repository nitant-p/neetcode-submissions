class Twitter:

    def __init__(self):
        self.tweetCount = 0
        self.userToFollower = {}
        self.tweetMap = {}

    def postTweet(self, userId: int, tweetId: int) -> None:
        if userId not in self.tweetMap:
            self.tweetMap[userId] = []

        self.tweetMap[userId].append((self.tweetCount, userId, len(self.tweetMap[userId]), tweetId))
        self.tweetCount -= 1

    def getNewsFeed(self, userId: int) -> list[int]:
        # make heap using latest posts from all followers (end of the list)
        if userId not in self.userToFollower:
            self.userToFollower[userId] = set()
        self.userToFollower[userId].add(userId) # self follow

        # print(self.userToFollower[userId])

        import heapq
        h = []
        for f in self.userToFollower[userId]:
            if f in self.tweetMap:
                posts = self.tweetMap[f]
                h.append(posts[-1])

        heapq.heapify(h) # heapify at the end for O(n) for n tweers instead of one at a time which is O(nlogn)

        topTen = []
        while h and len(topTen) < 10:
            _, userId, tweetIndex, tweetId = heapq.heappop(h)
            topTen.append(tweetId)

            nextIndex = tweetIndex - 1
            if nextIndex >= 0:
                heapq.heappush(h, self.tweetMap[userId][nextIndex])

        return topTen


    def follow(self, followerId: int, followeeId: int) -> None:
        if followerId not in self.userToFollower:
            self.userToFollower[followerId] = set()

        self.userToFollower[followerId].add(followeeId)

    def unfollow(self, followerId: int, followeeId: int) -> None:
        if followerId in self.userToFollower:
            self.userToFollower[followerId].discard(followeeId)


# Your Twitter object will be instantiated and called as such:
# obj = Twitter()
# obj.postTweet(userId,tweetId)
# param_2 = obj.getNewsFeed(userId)
# obj.follow(followerId,followeeId)
# obj.unfollow(followerId,followeeId)