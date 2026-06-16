class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<tuple<double, int>> heap;
        for (auto i = 0; i < points.size(); ++i) {
            tuple<double, int> entry = {calcDistance(points[i][0], points[i][1]), i};
            heap.push(entry);
        }

        while (heap.size() > k) heap.pop();



        vector<vector<int>> res;
        while (!heap.empty()) {
            // cout <<"lol"<<endl;
            // cout<< get<1>(heap.top());
            res.push_back(points[get<1>(heap.top())]);
            heap.pop();
        }
        return res;
     }

    double calcDistance(int x, int y) {
        return sqrt(pow(x, 2) + pow(y, 2));
    }
};
