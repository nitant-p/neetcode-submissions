class KthLargest {
public:

    priority_queue<int, vector<int>, greater<int>> minHeap;
    int maxSize;

    KthLargest(int k, vector<int>& nums) {
        maxSize = k;
        for (auto i : nums) {
            if (minHeap.size() >= maxSize) {
                if (minHeap.top() < i) { // must be in top k
                    minHeap.pop();
                    minHeap.push(i);
                }
            } else {
                minHeap.push(i);
            }
        }

    }
    
    int add(int val) {
        if (minHeap.size() >= maxSize) {
            if (minHeap.top() < val) { // must be in top k
                minHeap.pop();
                minHeap.push(val);
            }
        } else {
            minHeap.push(val);
        }
        return minHeap.top();
    }
};
