#include <bits/stdc++.h>
using namespace std;

// @leet start
class Solution {
 public:
  int minCost(string colors, vector<int>& neededTime) {
    int n = colors.size();
    if (n == 1) return 0;

    int mx = neededTime[0];
    int sum = neededTime[0];
    int result = 0;
    for (int i = 1; i < n; i++) {
      if (colors[i] == colors[i - 1]) {
        sum += neededTime[i];
        mx = max(mx, neededTime[i]);
      } else {
        result += (sum - mx);
        mx = neededTime[i];
        sum = neededTime[i];
      }
    }

    result += (sum - mx);

    return result;
  }
};
// @leet end

int main() {}
