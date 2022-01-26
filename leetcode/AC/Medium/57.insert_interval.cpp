/*
 * FILE: 57.insert_interval.cpp
 * @author: Arafat Hasan Jenin <opendoor.arafat[at]gmail[dot]com>
 * LINK: https://leetcode.com/problems/insert-interval/
 * DATE CREATED: 27-01-22 00:58:51 (+06)
 * LAST MODIFIED: 27-01-22 00:59:24 (+06)
 * VERDICT: Accepetd
 */

class Solution {
 public:
  vector<vector<int>> insert(vector<vector<int>>& intervals,
                             vector<int>& newInterval) {
    intervals.push_back(newInterval);
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> res;
    int start = intervals[0][0];
    int end = start;
    for (auto interval : intervals) {
      int intervalStart = interval[0];
      int intervalEnd = interval[1];
      if (intervalStart >= start && intervalStart <= end) {
        end = max(end, intervalEnd);
      } else {
        res.push_back({start, end});
        start = intervalStart;
        end = intervalEnd;
      }
    }
    res.push_back({start, end});
    return res;
  }
};
