/*
 * FILE: 56.merge_intervals.cpp
 * @author: Arafat Hasan Jenin <opendoor.arafat[at]gmail[dot]com>
 * LINK: https://leetcode.com/problems/merge-intervals/
 * DATE CREATED: 26-01-22 17:15:08 (+06)
 * LAST MODIFIED: 27-01-22 00:51:28 (+06)
 * VERDICT: Accepetd
 */

class Solution {
 public:
  vector<vector<int>> merge(vector<vector<int>>& intervals) {
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
