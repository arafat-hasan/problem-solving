/*
 * FILE: 40.combination_sum_ii.cpp
 * @author: Arafat Hasan Jenin <opendoor.arafat[at]gmail[dot]com>
 * LINK: https://leetcode.com/problems/combination-sum-ii/
 * DATE CREATED: 17-02-22 16:18:18 (+06)
 * LAST MODIFIED: 17-02-22 18:51:24 (+06)
 * VERDICT: Accepetd
 */

class Solution {
 public:
  vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end());
    for (int i : candidates) freq[i]++;
    auto ip = unique(candidates.begin(), candidates.end());
    candidates.resize(distance(candidates.begin(), ip));
    this->candidates = &candidates;
    this->target = &target;
    backtrack(vector<int>(), 0, 0);
    return res;
  }

 private:
  vector<vector<int>> res;
  vector<int>* candidates;
  map<int, int> freq;
  int *target, total = 0;

  void backtrack(vector<int> sub, int pos, int times) {
    if (times > freq[candidates->at(pos)]) return;
    if (total == (*target)) {
      res.push_back(sub);
      return;
    } else if (total > (*target)) {
      return;
    }

    for (int i = pos; i < (int)candidates->size(); ++i) {
      sub.push_back(candidates->at(i));
      total += candidates->at(i);
      backtrack(sub, i, pos == i ? times + 1 : 1);
      total -= candidates->at(i);
      sub.pop_back();
    }
  }
};
