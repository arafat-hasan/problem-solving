/*
 * FILE: 560.subarray_sum_equals_k.cpp
 * @author: Arafat Hasan Jenin <opendoor.arafat[at]gmail[dot]com>
 * LINK: https://leetcode.com/problems/subarray-sum-equals-k/
 * DATE CREATED: 11-02-22 01:01:51 (+06)
 * LAST MODIFIED: 11-02-22 01:06:57 (+06)
 * VERDICT: Accepetd
 */

class Solution {
 public:
  int subarraySum(vector<int>& nums, int k) {
    int count = 0;
    int sum = 0;
    unordered_map<int, int> mp;
    for (int i : nums) {
      sum += i;
      if (sum == k) count++;
      if (mp.find(sum - k) != mp.end()) count += mp[sum - k];
      mp[sum]++;
    }
    return count;
  }
};
