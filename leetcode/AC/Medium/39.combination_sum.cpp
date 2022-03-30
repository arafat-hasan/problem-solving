/*
 * FILE: 39.combination_sum.cpp
 * @author: Arafat Hasan Jenin <opendoor.arafat[at]gmail[dot]com>
 * LINK: https://leetcode.com/problems/combination-sum/
 * DATE CREATED: 17-02-22 13:46:19 (+06)
 * LAST MODIFIED: 17-02-22 16:07:30 (+06)
 * VERDICT: Accepetd
 */

class Solution {
 public:
  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    nums = &candidates;
    this->target = &target;
    backtrack(vector<int>(), 0);
    return res;
  }

 private:
  vector<vector<int>> res;
  vector<int>* nums;
  int total = 0, *target;
  void backtrack(vector<int> sub, int pos) {
    if (total == (*target)) {
      res.push_back(sub);
      return;
    } else if (total > (*target)) {
      return;
    }

    for (int i = pos; i < (int)nums->size(); ++i) {
      sub.push_back(nums->at(i));
      total += nums->at(i);
      backtrack(sub, i);
      sub.pop_back();
      total -= nums->at(i);
    }
  }
};
