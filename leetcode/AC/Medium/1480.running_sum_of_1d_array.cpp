/*
 * FILE: 1480.running_sum_of_1d_array.cpp
 * @author: Arafat Hasan Jenin <opendoor.arafat[at]gmail[dot]com>
 * LINK: https://leetcode.com/problems/running-sum-of-1d-array/
 * DATE CREATED: 11-03-22 17:47:32 (+06)
 * LAST MODIFIED: 11-03-22 18:00:06 (+06)
 * VERDICT: Accepetd
 */

class Solution {
 public:
  vector<int> runningSum(vector<int>& nums) {
    int prev = 0;
    for (int& i : nums) {
      i += prev;
      prev = i;
    }
    return nums;
  }
};
