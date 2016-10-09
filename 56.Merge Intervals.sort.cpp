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
    if (intervals.empty()) return {};
    vector<Interval> res;
    sort(intervals.begin(), intervals.end(), [](Interval a, Interval b) {
        return a.start < b.start;
      });
    res.push_back(intervals.front());
    for (auto & i : intervals) {
      auto &b = res.back();
      if (i.start <= b.end) {
        b.end = max(i.end, b.end);
      } else {
        res.push_back(i);
      }
    }
    return res;
  }
};
