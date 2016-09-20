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
private:
    Interval merge(const Interval& a, const Interval& b) {
        return Interval(a.start < b.start ? a.start : b.start, a.end > b.end ? a.end : b.end);
    }
    bool isOverlaped(const Interval& a, const Interval& b) {
        return (a.start < b.end && a.end >= b.start) || (b.start < a.end && b.end >= a.start);
    }
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        int len = intervals.size();
        auto it = intervals.begin();
        auto end = intervals.end();
        for (;it != end; ++it) {
            if (it->start > newInterval.start) break;
        }
        vector<Interval> res(intervals.begin(), it);
        
        if (!res.empty() && isOverlaped(res.back(), newInterval)) {
            newInterval = merge(res.back(), newInterval);
            res.pop_back();
        }
        
        for (;it != end && isOverlaped(*it, newInterval); ++it) {
            newInterval = merge(*it, newInterval);
        }
        res.push_back(newInterval);
        for (;it != end; ++it) {
            res.push_back(*it);
        }
        return res;
    }
};

// 584 54%
