/*
 * FILE: 217.contains_duplicate.cpp
 * @author: Arafat Hasan Jenin <opendoor.arafat[at]gmail[dot]com>
 * LINK: https://leetcode.com/problems/contains-duplicate/
 * DATE CREATED: 14-02-22 16:35:22 (+06)
 * LAST MODIFIED: 14-02-22 16:35:40 (+06)
 * VERDICT: Accepetd
 */

class Solution {
 public:
  Solution() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
  }
  bool containsDuplicate(vector<int>& nums) {
    unordered_map<int, int> freq;
    for (int i : nums) {
      freq[i]++;
      if (freq[i] > 1) return true;
    }
    return false;
  }
};
