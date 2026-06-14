class Solution {
public:

    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> heap;
        for (int s : stones) heap.push(s);

        while (heap.size() > 1) {
            int heaviest = heap.top();
            heap.pop();

            int sHeaviest = heap.top();
            heap.pop();

            if (heaviest > sHeaviest) {
                heaviest -= sHeaviest;
                heap.push(heaviest);
            }
        }

        return heap.size() == 1 ? heap.top() : 0;
    }
};
