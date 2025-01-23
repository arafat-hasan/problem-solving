/*
 * FILE: min-cost-climbing-stairs.cpp
 * @author: Arafat Hasan Jenin <opendoor.arafat[at]gmail[dot]com>
 * LINK: https://leetcode.com/problems/min-cost-climbing-stairs/
 * DATE CREATED: 26-01-21 00:51:44 (+06)
 * LAST MODIFIED: 26-01-21 01:17:10 (+06)
 * VERDICT: Accepetd
 * VERSION: 1.0
 * DESCRIPTION: Deleted code is debugged code.
 */


class Solution1 {
  public:
    int minCostClimbingStairs(vector<int>& cost) {
      memset(dp, -1, sizeof(dp));
      return min(solve(cost, 0), solve(cost, 1));
    }

  private:
    int dp[1002];
    int solve(vector<int>& cost, int pos) {
      if (pos >= (int)cost.size()) return 0;

      if (dp[pos] != -1) return dp[pos];
      dp[pos] = min(solve(cost, pos + 1), solve(cost, pos + 2)) + cost[pos];
      return dp[pos];
    }
};

class Solution {
  public:
    int minCostClimbingStairs(vector<int>& cost) {
      vector<int> calc = cost;
      for(int i = calc.size() - 3; i >= 0; i--){
        calc[i] =  min(calc[i+1], calc[i+2]) + calc[i];
      }
      return min(calc[0], calc[1]);
    }
};


