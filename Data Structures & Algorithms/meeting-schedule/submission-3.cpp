/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(),
            [](const Interval& a, const Interval& b) {
                if (a.start == b.start) return a.end < b.end;
                return a.start < b.start;
            }
        );

        int i = 0;
        while (i + 1 < intervals.size()) {
            if (intervals[i + 1].start < intervals[i].end) return false;
            ++i;
        }
        return true;
    }
};
