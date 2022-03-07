/*
 * FILE: 896.monotonic_array.cpp
 * @author: Arafat Hasan Jenin <opendoor.arafat[at]gmail[dot]com>
 * LINK: https://leetcode.com/problems/monotonic-array/
 * DATE CREATED: 03-03-22 00:56:18 (+06)
 * LAST MODIFIED: 03-03-22 00:56:26 (+06)
 * VERDICT: Accepetd
 */

class Solution {
 public:
  bool isMonotonic(vector<int>& nums) {
    if (nums.size() <= 2) return true;
    bool isIncr = nums[nums.size() - 1] > nums[0];
    for (int i = 1; i < (int)nums.size(); ++i) {
      if (isIncr) {
        if (nums[i] < nums[i - 1]) return false;
      } else {
        if (nums[i] > nums[i - 1]) return false;
      }
    }
    return true;
  }
};
