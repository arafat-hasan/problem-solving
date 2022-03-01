/*
 * FILE: 228.summary_ranges.cpp
 * @author: Arafat Hasan Jenin <opendoor.arafat[at]gmail[dot]com>
 * LINK: https://leetcode.com/problems/summary-ranges/
 * DATE CREATED: 28-02-22 13:43:06 (+06)
 * LAST MODIFIED: 28-02-22 20:09:39 (+06)
 * VERDICT: Accepetd
 */

class Solution {
 public:
  vector<string> summaryRanges(vector<int>& nums) {
    vector<string> res;
    int i = 0;
    while (i < nums.size()) {
      int start = i;
      string str = "";
      while (i + 1 < nums.size() && nums[i] + 1 == nums[i + 1]) {
        i++;
      }
      int end = i;
      str += to_string(nums[start]);
      if (start != end) {
        str += "->";
        str += to_string(nums[end]);
      }
      res.push_back(str);
      i++;
    }
    return res;
  }
};
