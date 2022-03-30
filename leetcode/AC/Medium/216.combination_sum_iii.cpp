/*
 * FILE: 216.combination_sum_iii.cpp
 * @author: Arafat Hasan Jenin <opendoor.arafat[at]gmail[dot]com>
 * LINK: https://leetcode.com/problems/combination-sum-iii/
 * DATE CREATED: 17-02-22 19:01:14 (+06)
 * LAST MODIFIED: 17-02-22 19:17:55 (+06)
 * VERDICT: Accepetd
 */

class Solution {
 public:
  Solution() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
  }

  vector<vector<int>> combinationSum3(int k, int n) {
    this->n = &n;
    this->k = &k;
    backtrack(vector<int>(), 1);
    return res;
  }

 private:
  int *n, *k, sum = 0;
  vector<vector<int>> res;
  void backtrack(vector<int> sub, int current) {
    if ((int)sub.size() > (*k)) return;
    if ((int)sub.size() == (*k)) {
      if (sum == (*n)) res.push_back(sub);
      return;
    }

    for (int i = current; i < 10; ++i) {
      sub.push_back(i);
      sum += i;
      backtrack(sub, i + 1);
      sum -= i;
      sub.pop_back();
    }
  }
};
