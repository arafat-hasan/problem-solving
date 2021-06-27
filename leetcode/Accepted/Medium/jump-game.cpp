/*
 * FILE: jump-game.cpp
 * @author: Arafat Hasan Jenin <opendoor.arafat[at]gmail[dot]com>
 * LINK: https://leetcode.com/problems/jump-game/
 * DATE CREATED: 26-02-21 18:24:22 (+06)
 * LAST MODIFIED: 26-02-21 18:53:04 (+06)
 * VERDICT:
 * VERSION: 1.0
 * DESCRIPTION: Deleted code is debugged code.
 */

class Solution {
 public:
  bool canJump(vector<int>& nums) {
    int i = 0;
    for (int reach = 0; i < (int)nums.size() and i <= reach; ++i) {
      reach = max(i + nums[i], reach);
    }
    return i == nums.size();
  }
};
