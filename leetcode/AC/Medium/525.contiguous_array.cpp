/*
 * FILE: 525.contiguous_array.cpp
 * @author: Arafat Hasan Jenin <opendoor.arafat[at]gmail[dot]com>
 * LINK: https://leetcode.com/problems/contiguous-array/
 * DATE CREATED: 04-02-22 22:41:26 (+06)
 * LAST MODIFIED: 04-02-22 22:55:02 (+06)
 * VERDICT: Accepetd
 */

class Solution {
 public:
  int findMaxLength(vector<int>& nums) {
    int sum = 0, maxLen = 0;
    unordered_map<int, int> seen{{0, -1}};

    for (int i = 0; i < (int)nums.size(); ++i) {
      sum += (nums[i] == 1 ? 1 : -1);
      if (seen.count(sum))
        maxLen = max(maxLen, i - seen[sum]);
      else
        seen[sum] = i;
    }
    return maxLen;
  }
};
