/*
 * FILE: 80.remove_duplicates_from_sorted_array_ii.cpp
 * @author: Arafat Hasan Jenin <opendoor.arafat[at]gmail[dot]com>
 * LINK: https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/
 * DATE CREATED: 06-02-22 16:50:48 (+06)
 * LAST MODIFIED: 06-02-22 16:57:18 (+06)
 * VERDICT: Accepetd
 */

class Solution {
 public:
  int removeDuplicates(vector<int>& nums) {
    int count = 1, last = nums[0], k = (int)nums.size();
    for (int i = 1; i < (int)nums.size(); i++) {
      if (nums[i] == last) {
        count++;
      } else {
        last = nums[i];
        count = 1;
      }

      if (count > 2) {
        nums[i] = INT_MAX;
        k--;
      }
    }

    sort(nums.begin(), nums.end());
    return k;
  }
};
