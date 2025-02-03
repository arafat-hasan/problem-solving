/*
 * FILE: 88.merge_sorted_array.cpp
 * @author: Arafat Hasan Jenin <opendoor.arafat[at]gmail[dot]com>
 * LINK: https://leetcode.com/problems/merge-sorted-array/
 * DATE CREATED: 06-02-22 03:06:22 (+06)
 * LAST MODIFIED: 06-02-22 03:15:30 (+06)
 * VERDICT: Accepetd
 */

class Solution {
 public:
  void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    for (int i = m - 1, j = n - 1, k = m + n - 1; k >= 0; k--) {
      int karim = i >= 0 ? nums1[i] : INT_MIN;
      int selim = j >= 0 ? nums2[j] : INT_MIN;
      int maxNow = INT_MIN;
      if (selim > karim) {
        maxNow = selim;
        j--;
      } else {
        maxNow = karim;
        i--;
      }
      nums1[k] = maxNow;
    }
  }
};
