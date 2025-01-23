/*
 * FILE: 78.subsets.cpp
 * @author: Arafat Hasan Jenin <opendoor.arafat[at]gmail[dot]com>
 * LINK: https://leetcode.com/problems/subsets/
 * DATE CREATED: 13-02-22 16:09:07 (+06)
 * LAST MODIFIED: 14-02-22 01:23:40 (+06)
 * VERDICT: Accepetd
 */

class Solution {
 public:
  vector<vector<int>> subsets(vector<int>& nums) {
    numList = nums;
    n = nums.size();
    vector<int> tmp;
    backtrack(0, tmp);
    return res;
  }

 private:
  vector<vector<int>> res;
  vector<int> numList;
  int n;
  void backtrack(int start, vector<int> sub) {
    res.push_back(sub);
    for (int i = start; i < n; ++i) {
      sub.push_back(numList[i]);
      backtrack(i + 1, sub);
      sub.pop_back();
    }
  }
};
