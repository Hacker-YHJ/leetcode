/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> res;
        if (intervals.size() == 0) return res;
        
        vector<Interval> sorted = intervals;
        Interval *s = nullptr;
        sort(sorted.begin(), sorted.end(), [](Interval a, Interval b) {
            return a.start < b.start;
        });
        s = &sorted[0];
        for (int i = 1, j = sorted.size(); i < j; ++i) {
            if (s->end >= sorted[i].start) s->end = s->end > sorted[i].end ? s->end : sorted[i].end;
            else {
                res.push_back(*s);
                s = &sorted[i];
            }
        }
        if (s) res.push_back(*s);
        return res;
    }
};

// 584ms 51%
