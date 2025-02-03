/*
 * FILE: 41.first_missing_positive.cpp
 * @author: Arafat Hasan Jenin <opendoor.arafat[at]gmail[dot]com>
 * LINK: https://leetcode.com/problems/first-missing-positive/
 * DATE CREATED: 28-02-22 20:12:13 (+06)
 * LAST MODIFIED: 28-02-22 23:26:27 (+06)
 * VERDICT: Accepetd
 */

class Solution {
 public:
  int firstMissingPositive(vector<int>& nums) {
    int exitingPos = -1;
    for (int i : nums)
      if (i > 0) {
        exitingPos = i;
        break;
      }
    if (exitingPos == -1) return 1;
    for (int& i : nums) {
      if (i <= 0) i = exitingPos;
    }

    for (int i = 0; i < (int)nums.size(); ++i) {
      int curIdx = abs(nums[i]) - 1;
      if (curIdx < 0 || curIdx >= nums.size()) continue;
      if (nums[curIdx] > 0) nums[curIdx] *= -1;
    }

    for (int i = 0; i < (int)nums.size(); ++i)
      if (nums[i] > 0) return i + 1;
    return nums.size() + 1;
  }
};
