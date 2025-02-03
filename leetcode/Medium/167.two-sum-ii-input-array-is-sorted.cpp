#include <bits/stdc++.h>

#include <algorithm>

using namespace std;
// @leet start
class Solution {
 public:
  vector<int> twoSum(vector<int>& numbers, int target) {
    set<int> s(numbers.begin(), numbers.end());
    map<int, vector<int>> m;
    vector<int> res(2);
    for (int i = 0; i < (int)numbers.size(); i++) {
      m[numbers[i]].push_back(i);
    }

    for (int i = 0; i < (int)numbers.size(); i++) {
      int num1 = numbers[i];
      int num2 = target - numbers[i];
      if (num1 == num2 and (int) m[num1].size() == 1) continue;

      if (s.count(num2)) {
        res[0] = i + 1;
        res[1] = m[num2][0] + 1;
      }
    }
    sort(res.begin(), res.end());
    return res;
  }
};
// @leet end

int main() { return 0; }
