/*
 * FILE: 442.find_all_duplicates_in_an_array.cpp
 * @author: Arafat Hasan Jenin <opendoor.arafat[at]gmail[dot]com>
 * LINK: https://leetcode.com/problems/find-all-duplicates-in-an-array/
 * DATE CREATED: 07-02-22 01:30:09 (+06)
 * LAST MODIFIED: 07-02-22 01:30:29 (+06)
 * VERDICT: Accepetd
 */

class Solution {
 public:
  vector<int> findDuplicates(vector<int>& nums) {
    map<int, int> freq;
    vector<int> res;
    for (int i : nums) freq[i]++;
    for (auto i : freq)
      if (i.second > 1) res.push_back(i.first);
    return res;
  }
};
