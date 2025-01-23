/*
 * FILE: 287.find_the_duplicate_number.cpp
 * @author: Arafat Hasan Jenin <opendoor.arafat[at]gmail[dot]com>
 * LINK: https://leetcode.com/problems/find-the-duplicate-number/
 * DATE CREATED: 07-02-22 01:41:45 (+06)
 * LAST MODIFIED: 07-02-22 01:45:22 (+06)
 * VERDICT: Accepetd
 */

class Solution {
 public:
  Solution() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
  }

  int findDuplicate(vector<int>& nums) {
    for (int i = 0; i < (int)nums.size(); ++i) {
      int index = abs(nums[i]) - 1;
      nums[index] *= -1;
      if (nums[index] > 0) return abs(nums[i]);
    }
    return -1;
  }

  // Accepted Solution: 678 ms, 103.4 MB
  // int findDuplicate(vector<int>& nums) {
  //  map<int, int> freq;
  //  for (int i : nums) freq[i]++;
  //  int ans = -1;
  //  for (auto i : freq) {
  //    if (i.second > 1) {
  //      ans = i.first;
  //      break;
  //    }
  //  }
  //  return ans;
  //}
};
