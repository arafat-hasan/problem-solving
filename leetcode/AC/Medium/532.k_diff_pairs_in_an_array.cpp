/*
 * FILE: 532.k_diff_pairs_in_an_array.cpp
 * @author: Arafat Hasan Jenin <opendoor.arafat[at]gmail[dot]com>
 * LINK: https://leetcode.com/problems/k-diff-pairs-in-an-array/
 * DATE CREATED: 10-02-22 02:03:26 (+06)
 * LAST MODIFIED: 10-02-22 02:07:32 (+06)
 * VERDICT: Accepetd
 */

class Solution {
 public:
  int findPairs(vector<int>& nums, int k) {
    set<pair<int, int>> uniquePairs;
    sort(nums.begin(), nums.end());

    for (int i = 0; i < (int)nums.size(); i++) {
      for (int j = i + 1; j < (int)nums.size(); j++) {
        if (nums[j] - nums[i] == k) {
          uniquePairs.insert({nums[i], nums[j]});
          break;
        } else if (nums[j] - nums[i] > k) {
          break;
        }
      }
    }
    return (int)uniquePairs.size();
  }
};
