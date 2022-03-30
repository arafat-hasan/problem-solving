/*
 * FILE: 169.majority_element.cpp
 * @author: Arafat Hasan Jenin <opendoor.arafat[at]gmail[dot]com>
 * LINK: https://leetcode.com/problems/majority-element/
 * DATE CREATED: 21-02-22 11:59:46 (+06)
 * LAST MODIFIED: 21-02-22 12:33:56 (+06)
 * VERDICT: Accepetd
 */

// Accepted: 23ms
class Solution {
 public:
  int majorityElement(vector<int>& nums) {
    int mei = 0, count = 1;
    for (int i = 1; i < (int)nums.size(); ++i) {
      if (nums[mei] == nums[i])
        count++;
      else {
        count--;
      }
      if (count <= 0) {
        mei = i;
        count = 1;
      }
    }
    return nums[mei];
  }
};

// Accepted: 20ms
// class Solution {
// public:
//  int majorityElement(vector<int>& nums) {
//    sort(nums.begin(), nums.end());
//    return nums[(int)nums.size() / 2];
//  }
//};
