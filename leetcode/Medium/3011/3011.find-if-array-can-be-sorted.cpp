#include <bits/stdc++.h>
using namespace std;

// @leet start
class Solution {
 public:
  bool canSortArray(vector<int>& nums) {
    vector<pair<int, int>> v;
    for (int i = 0; i < (int)nums.size(); i++) {
      v.push_back({nums[i], i});
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < (int)v.size(); i++) {
      int left = min(i, v[i].second);
      int right = max(i, v[i].second);
      int pop_count = __builtin_popcount(nums[left]);
      for (int j = left; j <= right; j++) {
        int cur_pop_count = __builtin_popcount(nums[j]);
        if (cur_pop_count != pop_count) return false;
      }
    }
    return true;
  }
};
// @leet end

int main() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++) cin >> v[i];
  Solution sol;
  cout << sol.canSortArray(v) << endl;
  return 0;
}
