/*
 * FILE: 977.squares_of_a_sorted_array.cpp
 * @author: Arafat Hasan Jenin <opendoor.arafat[at]gmail[dot]com>
 * LINK: https://leetcode.com/problems/squares-of-a-sorted-array/
 * DATE CREATED: 06-02-22 03:16:48 (+06)
 * LAST MODIFIED: 06-02-22 03:19:52 (+06)
 * VERDICT: Accepetd
 */

class Solution {
 public:
  vector<int> sortedSquares(vector<int>& nums) {
    for (int i = 0; i < (int)nums.size(); ++i) {
      nums[i] *= nums[i];
    }
    sort(nums.begin(), nums.end());
    return nums;
  }
};
