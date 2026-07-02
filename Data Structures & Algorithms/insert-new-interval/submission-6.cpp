class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int i = 0;
        while (i < intervals.size()) {
            auto& curr = intervals[i];
            if (curr[0] >= newInterval[0]) {
                // insert
                intervals.insert(intervals.begin() + i, newInterval);
                break;
            } else if (i == intervals.size() - 1) {
                intervals.push_back(newInterval);
                break;
            }

            ++i;
        }

        // for (auto p : intervals) {
        //     cout << "[" << p[0] << ", " << p[1] << "]" << endl; 
        // }

        if (intervals.empty()) intervals.push_back(newInterval);

        int start = -1, end  = -1;
        i = 0;
        while (i + 1 < intervals.size()) {
            auto& curr = intervals[i];
        
            if (intervals[i + 1][0] <= curr[1]) {
                // cout << "curr 0: " << curr[0] << endl;
                // cout << "curr 1: " << curr[1] << endl;

                start = i;
                while (i + 1 < intervals.size() && intervals[i + 1][0] <= curr[1]) { 
                    curr[1] = max(curr[1], intervals[i + 1][1]);
                    ++i;
                    end = i;
                }
                break;
            }
            ++i;
        }

        // return intervals;

        if (start != -1 && end != -1) intervals.erase(intervals.begin() + start + 1, intervals.begin() + end + 1);
        
        return intervals;
    }
};
