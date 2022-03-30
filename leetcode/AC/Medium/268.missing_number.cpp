/*
 * FILE: 268.missing_number.cpp
 * @author: Arafat Hasan Jenin <opendoor.arafat[at]gmail[dot]com>
 * LINK: https://leetcode.com/problems/missing-number/
 * DATE CREATED: 07-02-22 02:41:44 (+06)
 * LAST MODIFIED: 07-02-22 02:41:52 (+06)
 * VERDICT: Accepetd
 */

class Solution {
 public:
  int missingNumber(vector<int>& nums) {
    int sum = 0;
    int n = (int)nums.size() + 1;
    for (int i : nums) sum += i;
    int total = (n * (n - 1)) / 2;
    return total - sum;
  }
};
