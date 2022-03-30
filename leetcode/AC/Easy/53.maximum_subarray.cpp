/*
 * FILE: 53.maximum_subarray.cpp
 * @author: Arafat Hasan Jenin <opendoor.arafat[at]gmail[dot]com>
 * LINK: https://leetcode.com/problems/maximum-subarray/
 * DATE CREATED: 26-01-21 00:21:57 (+06)
 * LAST MODIFIED: 12-02-22 03:01:59 (+06)
 * VERDICT: Accepetd
 */

class Solution {
 public:
  int maxSubArray(vector<int>& nums) {
    int sum = 0, maxSum = INT_MIN;
    for (int i : nums) {
      sum += i;
      maxSum = max(maxSum, sum);
      sum = sum < 0 ? 0 : sum;
    }
    return maxSum;
  }
};

// class Solution {
//  public:
//   int maxSubArray(vector<int>& nums) {
//     int sum = 0, maxSum = INT_MIN, finish = -1, local_start = 0, start = 0;
//     for (int i = 0; i < (int)nums.size(); ++i) {
//       sum += nums[i];

//      if (sum < 0) {
//        local_start = i + 1;
//        sum = 0;
//      } else if (maxSum < sum) {
//        start = local_start;
//        maxSum = sum;
//        finish = i;
//      }
//    }

//    if (finish != -1) {
//      return maxSum;
//    }

//    maxSum = nums[0];
//    start = finish = 0;

//    for (int i = 1; i < (int)nums.size(); ++i) {
//      if (maxSum < nums[i]) {
//        maxSum = nums[i];
//        start = finish = i;
//      }
//    }
//    return maxSum;
//  }
//};
