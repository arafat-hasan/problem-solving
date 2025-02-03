/*
 * FILE: 413.arithmetic_slices.cpp
 * @author: Arafat Hasan Jenin <opendoor.arafat[at]gmail[dot]com>
 * LINK: https://leetcode.com/problems/arithmetic-slices/
 * DATE CREATED: 03-03-22 18:46:06 (+06)
 * LAST MODIFIED: 04-03-22 02:01:29 (+06)
 * VERDICT: Accepetd
 */

class Solution {
 public:
  int numberOfArithmeticSlices(vector<int>& nums) {
    int slices = 0;
    for (int i = 2, prev = 0; i < nums.size(); i++)
      slices += (nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2])
                    ? ++prev
                    : (prev = 0);
    return slices;
  }
};
