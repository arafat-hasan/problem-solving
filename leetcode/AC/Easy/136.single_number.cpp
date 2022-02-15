/*
 * FILE: 136.single_number.cpp
 * @author: Arafat Hasan Jenin <opendoor.arafat[at]gmail[dot]com>
 * LINK: https://leetcode.com/problems/single-number/
 * DATE CREATED: 15-02-22 22:50:07 (+06)
 * LAST MODIFIED: 15-02-22 22:50:21 (+06)
 * VERDICT: Accepetd
 */

class Solution {
 public:
  int singleNumber(vector<int>& nums) {
    int ans = 0;
    for (int i : nums) ans ^= i;
    return ans;
  }
};
