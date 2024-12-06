#include <bits/stdc++.h>
using namespace std;
// @leet start
class Solution {
 public:
  int maxCount(vector<int> &banned, int n, int maxSum) {
    set<int> s(banned.begin(), banned.end());
    int sum = 0, count = 0;
    for (int i = 1; i <= n; i++) {
      if (!s.count(i) and sum + i <= maxSum) {
        sum += i;
        count++;
      }
    }

    return count;
  }
};
// @leet end

int main() {
  int size;
  cin >> size;
  vector<int> banned(size);
  int n, maxSum;
  for (int i = 0; i < size; i++) {
    cin >> banned[i];
  }
  cin >> n >> maxSum;
  Solution sol;
  cout << sol.maxCount(banned, n, maxSum) << endl;
  return 0;
}

