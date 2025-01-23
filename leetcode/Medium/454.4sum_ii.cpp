/*
 * FILE: 454.4sum_ii.cpp
 * @author: Arafat Hasan Jenin <opendoor.arafat[at]gmail[dot]com>
 * LINK: https://leetcode.com/problems/4sum-ii/
 * DATE CREATED: 03-02-22 22:13:22 (+06)
 * LAST MODIFIED: 03-02-22 22:36:32 (+06)
 * VERDICT: Accepetd
 */

class Solution {
 public:
  int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3,
                   vector<int>& nums4) {
    map<int, int> abSum;

    for (auto i : nums1) {
      for (auto j : nums2) {
        abSum[i + j] += 1;
      }
    }

    int count = 0;
    for (auto i : nums3) {
      for (auto j : nums4) {
        int sum = i + j;
        if (abSum.count(-sum) != 0) {
          count += abSum[-sum];
        }
      }
    }

    return count;
  }
};
