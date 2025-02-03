/*
 * FILE: 452.minimum_number_of_arrows_to_burst_balloons.cpp
 * @author: Arafat Hasan Jenin <opendoor.arafat[at]gmail[dot]com>
 * LINK:
 * https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/
 * DATE CREATED: 27-01-22 02:02:09 (+06)
 * LAST MODIFIED: 27-01-22 17:46:30 (+06)
 * VERDICT: Accepetd
 */

bool compair(vector<int> &a, vector<int> &b) { return a[1] < b[1]; }

class Solution {
 public:
  int findMinArrowShots(vector<vector<int>> &points) {
    sort(points.begin(), points.end(), compair);
    int lastFutush = points[0][1];
    int count = 1;
    for (int i = 1; i < (int)points.size(); i++) {
      int pointStart = points[i][0];
      int pointEnd = points[i][1];
      if (pointStart > lastFutush) {
        count++;
        lastFutush = pointEnd;
      }
    }
    return count;
  }
};
