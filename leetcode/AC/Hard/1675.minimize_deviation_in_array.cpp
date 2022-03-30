/*
 * FILE: 1675.minimize_deviation_in_array.cpp
 * @author: Arafat Hasan Jenin <opendoor.arafat[at]gmail[dot]com>
 * LINK: https://leetcode.com/problems/minimize-deviation-in-array/
 * DATE CREATED: 19-02-22 18:52:47 (+06)
 * LAST MODIFIED: 20-02-22 01:38:09 (+06)
 * VERDICT: Accepetd
 */

class Solution {
 public:
  int minimumDeviation(vector<int>& nums) {
    int res = INT_MAX, minN = INT_MAX;
    priority_queue<int> pq;
    for (int n : nums) {
      n = n % 2 ? n * 2 : n;
      pq.push(n);
      minN = min(minN, n);
    }

    while (pq.top() % 2 == 0) {
      res = min(res, pq.top() - minN);
      minN = min(minN, pq.top() / 2);
      pq.push(pq.top() / 2);
      pq.pop();
    }
    return min(res, pq.top() - minN);
  }
};
