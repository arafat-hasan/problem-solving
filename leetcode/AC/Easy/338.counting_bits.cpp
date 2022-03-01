/*
 * FILE: 338.counting_bits.cpp
 * @author: Arafat Hasan Jenin <opendoor.arafat[at]gmail[dot]com>
 * LINK: https://leetcode.com/problems/counting-bits/
 * DATE CREATED: 01-03-22 23:00:45 (+06)
 * LAST MODIFIED: 01-03-22 23:01:04 (+06)
 * VERDICT: Accepetd
 */

class Solution {
 public:
  vector<int> countBits(int n) {
    vector<int> res;
    res.push_back(0);
    for (int i = 1; i <= n; ++i) {
      res.push_back(res[i / 2] + i % 2);
    }
    return res;
  }
};
